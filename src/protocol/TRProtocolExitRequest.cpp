#include "TRProtocolExitRequest.hpp"

TRProtocolExitRequest::TRProtocolExitRequest() 
{}

TRProtocolExitRequest::~TRProtocolExitRequest() 
{}


void TRProtocolExitRequest::marshal(TRByteBuffer* byte_buffer) {
    TR_UNUSED(byte_buffer);
}


void TRProtocolExitRequest::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    TR_UNUSED(byte_buffer);
    TR_UNUSED(error);
}

void TRProtocolExitRequest::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}