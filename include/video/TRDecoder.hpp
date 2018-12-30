#ifndef __TYRANNO_DECODER_HEADER__
#define __TYRANNO_DECODER_HEADER__

#include "TRCodec.hpp"

class TRDecoder : public TRCodec {
public:
    explicit TRDecoder();
    virtual ~TRDecoder();

protected:
    virtual AVCodec* createCodec(TR_CODEC_ID codec_id);

private:

};

#endif