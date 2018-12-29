#include "TRProtocolTranscodingResponse.hpp"


TRProtocolTranscodingResponse::TRProtocolTranscodingResponse() 
{}

TRProtocolTranscodingResponse::~TRProtocolTranscodingResponse()
{}


void TRProtocolTranscodingResponse::marshal(TRByteBuffer* byte_buffer) {
    TR_UNUSED(byte_buffer);
}

void TRProtocolTranscodingResponse::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    TR_UNUSED(byte_buffer);
    TR_UNUSED(error);
}

void TRProtocolTranscodingResponse::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}