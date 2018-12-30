#include "TREncoder.hpp"


TREncoder::TREncoder() 
{}

TREncoder::~TREncoder()
{}


AVCodec* TREncoder::createCodec(TR_CODEC_ID codec_id) {
    AVCodec* codec = avcodec_find_encoder(codec_id);
    if (codec == NULL) {
        // Empty
    }

    return codec;
}