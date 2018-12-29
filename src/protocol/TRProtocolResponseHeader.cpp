#include "TRProtocolResponseHeader.hpp"

#include <cstring>

TRProtocolResponseHeader::TRProtocolResponseHeader() {
    Clear();
}

TRProtocolResponseHeader::~TRProtocolResponseHeader() {
    Clear();
}


void TRProtocolResponseHeader::SetResultCode(uint result_code) {
    this->header_data_.result_code_ = result_code;
}

void TRProtocolResponseHeader::SetErrorMessage(const char* error_message) {
    if (this->header_data_.error_message != NULL) {
        delete[] this->header_data_.error_message;
        this->header_data_.error_message = NULL;
    }

    this->header_data_.error_message_length = strlen(error_message);
    this->header_data_.error_message = new char[strlen(error_message) + 1];
    strcpy(this->header_data_.error_message, error_message);
}

void TRProtocolResponseHeader::SetErrorMessage(std::string& error_message) {
    SetErrorMessage(error_message.c_str());
}


uint TRProtocolResponseHeader::GetResultCode() {
    return this->header_data_.result_code_;
}

uint TRProtocolResponseHeader::GetErrorMessageLength() {
    return this->header_data_.error_message_length;
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

    int result_code_size = sizeof(this->header_data_.result_code_);
    int error_message_length_size = sizeof(this->header_data_.error_message_length);
    byte_buffer->Append((unsigned char*)&this->header_data_.result_code_, result_code_size);
    byte_buffer->Append((unsigned char*)&this->header_data_.error_message_length, error_message_length_size);
    
    if (this->header_data_.error_message != NULL) {
        byte_buffer->Append((unsigned char*)this->header_data_.error_message, this->header_data_.error_message_length);
    }
}

void TRProtocolResponseHeader::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    Clear();

    int header_size = sizeof(this->header_data_.result_code_)
                    + sizeof(this->header_data_.error_message_length);
    if (byte_buffer.GetLength() < header_size) {
        error->SetErrorValue(TRProtocol::UNMARSHAL_DATA_SIZE_NOT_ENOUGH, "TR Response header size not enough");
        return;
    }

    int result_code_size = sizeof(this->header_data_.result_code_);
    int error_message_length_size = sizeof(this->header_data_.error_message_length);
    this->header_data_.result_code_ = *(uint*)byte_buffer.Sub(0, result_code_size).GetData();
    this->header_data_.error_message_length = *(uint*)byte_buffer.Sub(result_code_size, result_code_size + error_message_length_size).GetData();
    
    if (this->header_data_.error_message_length > 0) {
        this->header_data_.error_message = new char[this->header_data_.error_message_length + 1];
        if (this->header_data_.error_message == NULL) {
            error->SetErrorValue(TRProtocol::MEMORY_ALLOC_FAILED, "TR Response header error message memory alloc is NULL");
            return;
        }
        memset(this->header_data_.error_message, '\0', this->header_data_.error_message_length + 1);

        int start_index = result_code_size + error_message_length_size;
        int end_index   = start_index + this->header_data_.error_message_length;
        TRByteBuffer error_message_byte_buffer = byte_buffer.Sub(start_index, end_index);
        memcpy(this->header_data_.error_message, error_message_byte_buffer.GetData(), error_message_byte_buffer.GetLength());
    }

    error->SetErrorCode(TRProtocol::SUCCESS);
}