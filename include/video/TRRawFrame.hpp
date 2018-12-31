#ifndef __TYRANNO_RAW_FRAME_HEADER__
#define __TYRANNO_RAW_FRAME_HEADER__

#include "TRError.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {
#include "libavcodec/avcodec.h"
};

class TRRawFrame {
public:
    explicit TRRawFrame();
    virtual ~TRRawFrame();

    friend class TRDecoder;
    friend class TREncoder;
    
public:
    void Clear();
 
private:
    AVFrame* frame_;
};

#endif