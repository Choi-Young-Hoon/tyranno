#include "TRProtocolRegistRequest.hpp"

#include <cstring>

TRProtocolRegistRequest::TRProtocolRegistRequest() 
{}

TRProtocolRegistRequest::~TRProtocolRegistRequest()
{}


void TRProtocolRegistRequest::marshal(TRByteBuffer* byte_buffer) {
    byte_buffer->Append((unsigned char*)&this->body_data_, sizeof(this->body_data_));
}

void TRProtocolRegistRequest::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    int minimum_size = sizeof(this->body_data_);
    if (byte_buffer.GetLength() < minimum_size) {
        error->SetErrorValue(TRProtocol::UNMARSHAL_DATA_SIZE_NOT_ENOUGH, "TR Protocol Regist body size not enough");
        return;
    }

    this->body_data_ = *(TR_PROTOCOL_REGIST_REQUEST*)byte_buffer.GetData();
    error->SetErrorCode(TRProtocol::SUCCESS);
}

void TRProtocolRegistRequest::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}

void TRProtocolRegistRequest::SetSystemVersion(TR_VERSION system_version) {
    this->body_data_.system_version = system_version;
}

TR_VERSION TRProtocolRegistRequest::GetSystemVersion() {
    return this->body_data_.system_version;
}