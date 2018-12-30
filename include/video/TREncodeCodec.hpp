#ifndef __TYRANNO_ENCODE_CODEC_HEADER__
#define __TYRANNO_ENCODE_CODEC_HEADER__

#include "TRCodec.hpp"

class TREncodeCodec : public TRCodec {
public:
    explicit TREncodeCodec();
    virtual ~TREncodeCodec();

protected:
    virtual AVCodec* createCodec(TR_CODEC_ID codec_id);
};

#endif