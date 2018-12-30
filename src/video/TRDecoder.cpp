#include "TRDecoder.hpp"


TRDecoder::TRDecoder()
: codec_(NULL)
{}

TRDecoder::~TRDecoder() {
    if (this->codec_ != NULL) {
        delete this->codec_;
    }
}


void TRDecoder::SetCodec(TRCodec* codec) {
    if (this->codec_ != NULL) {
        delete this->codec_;
    }
    this->codec_ = codec;
}

void TRDecoder::Decode(TRFrame& encoded_fram, TRRawFrame* decode_frame, TRError* error) {

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}