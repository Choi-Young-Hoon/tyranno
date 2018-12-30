#ifndef __TYRANNO_ENCODER_HEADER__
#define __TYRANNO_ENCODER_HEADER__

#include "TRCodec.hpp"

class TREncoder {
public:
    explicit TREncoder();
    virtual ~TREncoder();

public:
    void SetCodec(TRCodec* codec);

    void Encode(TRRawFrame& decoded_frame, TRFrame* encode_frame, TRError* error);

private:
    TRCodec* codec_;
};

#endif