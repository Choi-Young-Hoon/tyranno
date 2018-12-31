#ifndef __TYRANNO_VIDEO_HEADER__
#define __TYRANNO_VIDEO_HEADER__

#include "TR_VIDEO_TYPE.hpp"
#include "TRError.hpp"
#include "TRFrame.hpp"
#include "TRCodecID.hpp"
#include "TRCodecParameters.hpp"
#include "TRStreamIndex.hpp"

#include <string>

extern "C" {
#include "libavformat/avformat.h"
};

class TRVideo {
public:
    explicit TRVideo();
    virtual ~TRVideo();

public:
    void Open(std::string& file_name, TRError* error);
    void Open(const char* file_name, TRError* error);
    void Close();

    bool IsOpen();

    bool ReadFrame(TRFrame* frame, TRError* error);

    // get
    uint          GetStreamsCount();
    TRStreamIndex GetStreamIndex();
    TRCodecID         GetCodecID();
    TRCodecParameters GetCodecParameters();

private:
    // get
    TR_CODEC_ID        GetCodecID(int stream_index);
    AVCodecParameters* GetAVCodecParameters(int stream_index);

private:
    AVFormatContext* format_ctx_;

    TRStreamIndex stream_index_;
};

#endif