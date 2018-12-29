#include "TRProtocolMuxingRequest.hpp"


TRProtocolMuxingRequest::TRProtocolMuxingRequest() 
{}

TRProtocolMuxingRequest::~TRProtocolMuxingRequest() 
{}


void TRProtocolMuxingRequest::marshal(TRByteBuffer* byte_buffer) {
    TR_UNUSED(byte_buffer);
}

void TRProtocolMuxingRequest::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    TR_UNUSED(byte_buffer);
    TR_UNUSED(error);
}

void TRProtocolMuxingRequest::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}