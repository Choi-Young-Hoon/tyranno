#include "TRProtocolRequestHeader.hpp"

#include <cstring>

TRProtocolRequestHeader::TRProtocolRequestHeader() {
    Clear();
}

TRProtocolRequestHeader::~TRProtocolRequestHeader()
{}


uint TRProtocolRequestHeader::GetRequestType() {
    return this->header_data_.request_type_;
}

uint8_t TRProtocolRequestHeader::GetSystemType() {
    return this->header_data_.system_type_;
}

uint16_t TRProtocolRequestHeader::GetVersion() {
    return this->header_data_.version_;
}

uint TRProtocolRequestHeader::GetSession() {
    return this->header_data_.session_;
}

void TRProtocolRequestHeader::Clear() {
    memset(&this->header_data_, 0x00 ,sizeof(this->header_data_));
}

void TRProtocolRequestHeader::marshal(TRByteBuffer* byte_buffer) {
    byte_buffer->Clear();

    byte_buffer->SetData((unsigned char*)&this->header_data_, sizeof(this->header_data_));
}

void TRProtocolRequestHeader::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    int header_data_size = sizeof(this->header_data_);
    if (byte_buffer.GetLength() < header_data_size) {
        error->SetErrorValue(TRProtocol::UNMARSHAL_DATA_SIZE_NOT_ENOUGH, "TR Request header size not enough");
        return;
    }

    this->header_data_ = *(TR_PROTOCOL_REQUEST_HEADER*)byte_buffer.GetData();
    
    error->SetErrorCode(TRProtocol::SUCCESS);
}