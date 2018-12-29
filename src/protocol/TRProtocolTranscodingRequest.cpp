#include "TRProtocolTranscodingRequest.hpp"


TRProtocolTranscodingRequest::TRProtocolTranscodingRequest() 
{}

TRProtocolTranscodingRequest::~TRProtocolTranscodingRequest()
{}


void TRProtocolTranscodingRequest::marshal(TRByteBuffer* byte_buffer) {
    TR_UNUSED(byte_buffer);
}

void TRProtocolTranscodingRequest::unmarshal(TRByteBuffer& byte_buffer, TRError* error) {
    TR_UNUSED(byte_buffer);
    TR_UNUSED(error);
}

void TRProtocolTranscodingRequest::Clear() {
    memset(&this->body_data_, 0x00, sizeof(this->body_data_));
}