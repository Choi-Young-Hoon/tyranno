#include "TRProtocolRegistResponse.hpp"

#include <cstring>

TRProtocolRegistResponse::TRProtocolRegistResponse() 
{}

TRProtocolRegistResponse::~TRProtocolRegistResponse()
{}


void TRProtocolRegistResponse::marshal(TRByteBuffer* byte_buffer) {
    byte_buffer->Append((unsigned char*)&this->body_data_, sizeof(this->body_data_));
}

void TRProtocolRegistResponse::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    int minimum_size = sizeof(this->body_data_);
    if (byte_buffer.GetLength() < minimum_size) {
        error->SetErrorValue(TRProtocol::SUCCESS, "TR Protocol Regist Response body size not enough");
        return;
    }

    this->body_data_ = *(TP_PROTOCOL_REGIST_RESPONSE*)byte_buffer.GetData();
    error->SetErrorCode(TRProtocol::SUCCESS);
}


void TRProtocolRegistResponse::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}


void TRProtocolRegistResponse::SetSession(TR_SESSION session) {
    this->body_data_.session = session;
}

TR_SESSION TRProtocolRegistResponse::GetSession() {
    return this->body_data_.session;
}