#ifndef __TYRANNO_FRAME_HEADER__
#define __TYRANNO_FRAME_HEADER__

#include "TRError.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {
#include "libavcodec/avcodec.h"
};

class TRFrame {
public:
    explicit TRFrame();
    virtual ~TRFrame();

    friend class TRVideoReader;
    friend class TRDecoder;
    friend class TREncoder;
    
public:
    void Clear();

    // set
    void SetData(TRByteBuffer& byte_buffer);
    
    // get
    void GetData(TRByteBuffer* byte_buffer);

private:
    AVPacket packet_;
};

#endif