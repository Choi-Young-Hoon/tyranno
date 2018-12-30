#ifndef __TYRANNO_DECODE_CODEC_HEADER__
#define __TYRANNO_DECODE_CODEC_HEADER__

#include "TRCodec.hpp"

class TRDecodeCodec : public TRCodec {
public:
    explicit TRDecodeCodec();
    virtual ~TRDecodeCodec();

protected:
    virtual AVCodec* createCodec(TR_CODEC_ID codec_id);
    
};
#endif