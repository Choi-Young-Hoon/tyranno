#include "TRDecoder.hpp"


TRDecoder::TRDecoder()
{}

TRDecoder::~TRDecoder()
{}


AVCodec* TRDecoder::createCodec(TR_CODEC_ID codec_id) {
    AVCodec* codec = avcodec_find_decoder(codec_id);
    if (codec == NULL) {
        // Empty
    }

    return codec;
}