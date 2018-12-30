#include "TREncodeCodec.hpp"


TREncodeCodec::TREncodeCodec()
{}

TREncodeCodec::~TREncodeCodec()
{}


AVCodec* TREncodeCodec::createCodec(TR_CODEC_ID codec_id) {
    AVCodec* ret_codec = avcodec_find_encoder(codec_id);
    if (ret_codec == NULL) {
        // Empty
    }

    return ret_codec;
}