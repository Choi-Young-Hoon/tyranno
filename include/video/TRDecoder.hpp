#ifndef __TYRANNO_DECODER_HEADER__
#define __TYRANNO_DECODER_HEADER__

#include "TRCodec.hpp"

#include <string>

class TRDecoder{
public:
    explicit TRDecoder();
    virtual ~TRDecoder();

public:
    void SetCodec(TRCodec* codec);
    
    void Decode(TRFrame& encoded_frame, TRRawFrame* decode_frame, TRError* error);

private:
    TRCodec* codec_;
};

#endif