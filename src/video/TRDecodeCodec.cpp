#include "TRDecodeCodec.hpp"

TRDecodeCodec::TRDecodeCodec()
{}

TRDecodeCodec::~TRDecodeCodec()
{}


AVCodec* TRDecodeCodec::createCodec(TR_CODEC_ID codec_id) {
    if (codec_id < 0) {
        return NULL;
    }

    AVCodec* ret_codec = avcodec_find_decoder(codec_id);
    if (ret_codec == NULL) {
        // Empty
    }

    return ret_codec;
}

