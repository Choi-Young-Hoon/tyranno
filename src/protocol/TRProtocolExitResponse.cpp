#include "TRProtocolExitResponse.hpp"

TRProtocolExitResponse::TRProtocolExitResponse() 
{}

TRProtocolExitResponse::~TRProtocolExitResponse() 
{}


void TRProtocolExitResponse::marshal(TRByteBuffer* byte_buffer) {
    TR_UNUSED(byte_buffer);
}

void TRProtocolExitResponse::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    TR_UNUSED(byte_buffer);
    TR_UNUSED(error);
}

void TRProtocolExitResponse::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}