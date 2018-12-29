#include "TRProtocolRequestHeader.hpp"

#include <cstring>

TRProtocolRequestHeader::TRProtocolRequestHeader() {
    memset(&this->header_data_, 0x00 ,sizeof(this->header_data_));
}

TRProtocolRequestHeader::~TRProtocolRequestHeader()
{}


void TRProtocolRequestHeader::SetRequestType(uint request_type) {
    this->header_data_.request_type_ = request_type;
}

void TRProtocolRequestHeader::SetSystemType(uint8_t system_type) {
    this->header_data_.system_type_ = system_type;
}

void TRProtocolRequestHeader::SetVersion(uint16_t version) {
    this->header_data_.version_ = version;
}

void TRProtocolRequestHeader::SetSession(uint session) {
    this->header_data_.session_ = session;
}


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
        error->SetErrorValue(TRProtocolHeaderInterface::UNMARSHAL_DATA_SIZE_NOT_ENOUGH, "TR Request header size not enough");
        return;
    }

    this->header_data_ = *(TR_PROTOCOL_REQUEST_HEADER*)byte_buffer.GetData();
    
    error->SetErrorCode(TRProtocolHeaderInterface::SUCCESS);
}