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
    
    void Decode(TRVideo& video, std::string& output_file_name, TRError* error);
    void Decode(TRFrame& encoded_fram, TRRawFrame* decode_frame, TRError* error);

private:
    TRCodec* codec_;
};

#endif