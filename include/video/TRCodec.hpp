#ifndef __TYRANNO_CODEC_HEADER__
#define __TYRANNO_CODEC_HEADER__

#include "TRError.hpp"
#include "TRVideo.hpp"
#include "TRCodecID.hpp"
#include "TRRawFrame.hpp"

#include <list>

extern "C" {
#include "libavcodec/avcodec.h"
};

class TRCodec {
public:
    explicit TRCodec();
    virtual ~TRCodec();

    friend class TRDecoder;
    friend class TREncoder;
    
public:
    void InitializeCodec(TRCodecID& codec_id, TRError* error);
    void InitializeCodec(TRVideo& video, TRError* error);

    // set
    void SetVideoCodecCtx(AVCodecContext* video_codec_ctx);
    void SetAudioCodecCtx(AVCodecContext* audio_codec_ctx);
    
    // get
    AVCodecContext* GetVideoCodecCtx();
    AVCodecContext* GetAudioCodecCtx();

protected:
    // interface
    virtual AVCodec* createCodec(TR_CODEC_ID codec_id);

private:
    void InitializeVideoCodec(TR_CODEC_ID video, TRError* error);
    void InitializeAudioCodec(TR_CODEC_ID codec_id, TRError* error);

private:
    AVCodec* video_codec_;
    AVCodec* audio_codec_;

    AVCodecContext* video_codec_ctx_;
    AVCodecContext* audio_codec_ctx_;
};

#endif