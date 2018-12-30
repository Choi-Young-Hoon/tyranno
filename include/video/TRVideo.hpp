#ifndef __TYRANNO_VIDEO_HEADER__
#define __TYRANNO_VIDEO_HEADER__

#include "TR_VIDEO_TYPE.hpp"
#include "TRError.hpp"
#include "TRFrame.hpp"

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
    uint        GetStreamsCount();
    TR_CODEC_ID GetVideoCodecID();
    TR_CODEC_ID GetAudioCodecID();

private:
    // get
    TR_CODEC_ID GetCodecID(int stream_index);

private:
    AVFormatContext* format_ctx_;

    int video_stream_index_;
    int audio_stream_index_;
};

#endif