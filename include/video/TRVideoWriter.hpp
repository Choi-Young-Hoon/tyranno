#ifndef __TR_VIDEO_WRITE_HEADER__
#define __TR_VIDEO_WRITE_HEADER__

#include "TR_VIDEO_TYPE.hpp"
#include "TRError.hpp"
#include "TRFrame.hpp"
#include "TRCodecID.hpp"
#include "TRStreamIndex.hpp"

extern "C" {
#include "libavformat/avformat.h"
};

class TRVideoWriter {
public:
    explicit TRVideoWriter();
    virtual ~TRVideoWriter();

public:
    void Open(std::string& file_name, TRError* error);
    void Open(const char* file_name, TRError* error);
    void Close();

    bool IsOpen();

    bool WriteFrame(TRFrame* frame, TRError* error);

private:
    AVFormatContext* format_ctx_;
};

#endif