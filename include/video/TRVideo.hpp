#ifndef __TYRANNO_VIDEO_HEADER__
#define __TYRANNO_VIDEO_HEADER__

#include "TR_TYPE.hpp"
#include "TRError.hpp"
#include "TRFrame.hpp"

#include <string>

extern "C" {
#include "libavformat/avformat.h"
};

class TRVideo {
public:
    enum _ERROR_DEFINE {
        SUCCESS = 0,

        FILE_OPEN_FAILED,
        FILE_NOT_OPENED,
        STREAM_INFO_NOT_FOUND,

        READ_FRAME_FAILED,
    };
    typedef enum _ERROR_DEFINE ERROR_DEFINE;

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