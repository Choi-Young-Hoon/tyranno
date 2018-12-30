#include "TREncoder.hpp"


TREncoder::TREncoder()
: codec_(NULL)
{}

TREncoder::~TREncoder() {
    if (codec_ != NULL) {
        delete this->codec_;
    }
}


void TREncoder::SetCodec(TRCodec* codec) {
    if (this->codec_ != NULL) {
        delete this->codec_;
    }
    this->codec_ = codec;
}

void TREncoder::Encode(TRRawFrame& decoded_frame, TRFrame* encode_frame, TRError* error) {

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}