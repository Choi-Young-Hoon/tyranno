#include "TRProtocolResponseHeader.hpp"

#include <cstring>

TRProtocolResponseHeader::TRProtocolResponseHeader() {
    memset(&this->header_data_, 0x00 ,sizeof(this->header_data_));
}

TRProtocolResponseHeader::~TRProtocolResponseHeader() {
    Clear();
}


void TRProtocolResponseHeader::SetRequestType(uint request_type) {
    this->header_data_.data.request_type = request_type;
}

void TRProtocolResponseHeader::SetResultCode(uint result_code) {
    this->header_data_.data.result_code = result_code;
}

void TRProtocolResponseHeader::SetErrorMessage(const char* error_message) {
    if (this->header_data_.error_message != NULL) {
        delete[] this->header_data_.error_message;
        this->header_data_.error_message = NULL;
    }

    this->header_data_.data.error_message_length = strlen(error_message);
    this->header_data_.error_message = new char[strlen(error_message) + 1];
    strcpy(this->header_data_.error_message, error_message);
}

void TRProtocolResponseHeader::SetErrorMessage(std::string& error_message) {
    SetErrorMessage(error_message.c_str());
}


uint TRProtocolResponseHeader::GetRequestType() {
    return this->header_data_.data.request_type;
}

uint TRProtocolResponseHeader::GetResultCode() {
    return this->header_data_.data.result_code;
}

uint TRProtocolResponseHeader::GetErrorMessageLength() {
    return this->header_data_.data.error_message_length;
}

std::string TRProtocolResponseHeader::GetErrorMessage() {
    return this->header_data_.error_message;
}


void TRProtocolResponseHeader::Clear() {
    if (this->header_data_.error_message != NULL) {
        delete[] this->header_data_.error_message;
    }
    memset(&this->header_data_, 0x00, sizeof(this->header_data_));
}


void TRProtocolResponseHeader::marshal(TRByteBuffer* byte_buffer) {
    byte_buffer->Clear();

    byte_buffer->Append((unsigned char*)&this->header_data_.data, sizeof(this->header_data_.data));
   
    if (this->header_data_.error_message != NULL) {
        byte_buffer->Append((unsigned char*)this->header_data_.error_message, this->header_data_.data.error_message_length);
    }
}

void TRProtocolResponseHeader::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    Clear();

    int minimum_header_size = sizeof(this->header_data_.data);
    if (byte_buffer.GetLength() < minimum_header_size) {
        error->SetErrorValue(TRProtocolHeaderInterface::UNMARSHAL_DATA_SIZE_NOT_ENOUGH, "TR Response header size not enough");
        return;
    }

    this->header_data_.data = *(TR_PROTOCOL_RESPONSE_DATA*)byte_buffer.Sub(0, sizeof(this->header_data_.data)).GetData();
    if (this->header_data_.data.error_message_length > 0) {
        this->header_data_.error_message = new char[this->header_data_.data.error_message_length + 1];
        if (this->header_data_.error_message == NULL) {
            error->SetErrorValue(TRProtocolHeaderInterface::MEMORY_ALLOC_FAILED, "TR Response header error message memory allocate is NULL");
            return;
        }
        memset(this->header_data_.error_message, '\0', this->header_data_.data.error_message_length + 1);

        TRByteBuffer error_message_byte_buffer = byte_buffer.Sub(minimum_header_size, minimum_header_size + this->header_data_.data.error_message_length);
        memcpy(this->header_data_.error_message, error_message_byte_buffer.GetData(), error_message_byte_buffer.GetLength());
    }

    error->SetErrorCode(TRProtocolHeaderInterface::SUCCESS);
}