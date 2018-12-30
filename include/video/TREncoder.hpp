#ifndef __TYRANNO_ENCODER_HEADER__
#define __TYRANNO_ENCODER_HEADER__

#include "TRCodec.hpp"

class TREncoder : public TRCodec {
public:
    explicit TREncoder();
    virtual ~TREncoder();

protected:
    virtual AVCodec* createCodec(TR_CODEC_ID codec_id);

private:

};

#endif