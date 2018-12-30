#ifndef __TYRANNO_CODEC_HEADER__
#define __TYRANNO_CODEC_HEADER__

#include "TRError.hpp"
#include "TR_TYPE.hpp"
#include "TRVideo.hpp"

extern "C" {
#include "libavcodec/avcodec.h"
};

class TRCodec {
public:
    enum _ERROR_DEFINE {
        SUCCESS = 0,

        MEMORY_ALLOC_FAILED,
        NOT_FOUND_VIDEO_CODEC,
        NOT_FOUND_AUDIO_CODEC,
    };
    typedef enum _ERROR_DEFINE ERROR_DEFINE;

public: // create
    static TRCodec* create(TRVideo& video, TRError* error);

public:
    explicit TRCodec();
    virtual ~TRCodec();

public:
    void InitializeCodec(TRVideo& video, TRError* error);

protected:
    virtual AVCodec* createCodec(TR_CODEC_ID codec_id);
    virtual void     run(TRByteBuffer& task_before, TRByteBuffer* task_result, TRError* error);

protected:
    // set
    void SetVideoCodecCtx(AVCodecContext* video_codec_ctx);
    void SetAudioCodecCtx(AVCodecContext* audio_codec_ctx);
    
    // get
    AVCodecContext* GetVideoCodecCtx();
    AVCodecContext* GetAudioCodecCtx();

private:
    void InitializeVideoCodec(TRVideo& video, TRError* error);
    void InitializeAudioCodec(TRVideo& video, TRError* error);

private:
    AVCodec* video_codec_;
    AVCodec* audio_codec_;

    AVCodecContext* video_codec_ctx_;
    AVCodecContext* audio_codec_ctx_;
};

#endif