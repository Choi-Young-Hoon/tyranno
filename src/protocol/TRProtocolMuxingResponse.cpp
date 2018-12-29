#include "TRProtocolMuxingResponse.hpp"


TRProtocolMuxingResponse::TRProtocolMuxingResponse() 
{}

TRProtocolMuxingResponse::~TRProtocolMuxingResponse()
{}


void TRProtocolMuxingResponse::marshal(TRByteBuffer* byte_buffer) {
    TR_UNUSED(byte_buffer);
}

void TRProtocolMuxingResponse::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    TR_UNUSED(byte_buffer);
    TR_UNUSED(error);
}

void TRProtocolMuxingResponse::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}