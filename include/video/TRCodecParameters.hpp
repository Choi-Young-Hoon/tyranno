#ifndef __TYRANNO_CODEC_PARAMETERS_HEADER__
#define __TYRANNO_CODEC_PARAMETERS_HEADER__

extern "C" {
#include "libavcodec/avcodec.h"
}

class TRCodecParameters {
public:
    explicit TRCodecParameters();
    explicit TRCodecParameters(AVCodecParameters& video_codec_parameters, AVCodecParameters& audio_codec_parameters);
    virtual ~TRCodecParameters();

public:
    void Clear();

    bool IsVideoCodecParametersEmpty();
    bool IsAudioCodecParametersEmpty();

    void SetVideoAVCodecParameters(AVCodecParameters& video_codec_parameters);
    void SetAudioAVCodecParameters(AVCodecParameters& audio_codec_parameters);

    const AVCodecParameters* GetVideoAVCodecParameters();
    const AVCodecParameters* GetAudioAVCodecParameters();

public:
    TRCodecParameters& operator=(TRCodecParameters& codec_parameters);

private:
    bool IsCodecParametersNULL(AVCodecParameters* codec_parameter);

    void SetAVCodecParameters(AVCodecParameters** codec_parameters, AVCodecParameters& copy_target_parameters);

private:
    AVCodecParameters* video_codec_parameters_;
    AVCodecParameters* audio_codec_parameters_;
};

#endif