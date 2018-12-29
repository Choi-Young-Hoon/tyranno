#include "TRProtocolRequestHeader.hpp"

#include <cstring>

TRProtocolRequestHeader::TRProtocolRequestHeader() {
    this->header_data_.version = GetTRProtocolVersion();
}

TRProtocolRequestHeader::~TRProtocolRequestHeader()
{}


void TRProtocolRequestHeader::Clear() {
    memset(&this->header_data_, 0x00 ,sizeof(this->header_data_));

    this->header_data_.version = GetTRProtocolVersion();
}

void TRProtocolRequestHeader::marshal(TRByteBuffer* byte_buffer) {
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


void TRProtocolRequestHeader::SetRequestType(TR_REQUEST_TYPE request_type) {
    this->header_data_.request_type = request_type;
}

void TRProtocolRequestHeader::SetSystemType(TR_SYSTEM_TYPE system_type) {
    this->header_data_.system_type = system_type;
}

void TRProtocolRequestHeader::SetSession(TR_SESSION session) {
    this->header_data_.session = session;
}


TR_REQUEST_TYPE TRProtocolRequestHeader::GetRequestType() {
    return this->header_data_.request_type;
}

TR_SYSTEM_TYPE TRProtocolRequestHeader::GetSystemType() {
    return this->header_data_.system_type;
}

TR_VERSION TRProtocolRequestHeader::GetVersion() {
    return this->header_data_.version;
}

TR_SESSION TRProtocolRequestHeader::GetSession() {
    return this->header_data_.session;
}