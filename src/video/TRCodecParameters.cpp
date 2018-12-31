#include "TRCodecParameters.hpp"


TRCodecParameters::TRCodecParameters() {
    this->video_codec_parameters_ = NULL;
    this->audio_codec_parameters_ = NULL;
}

TRCodecParameters::TRCodecParameters(AVCodecParameters& video_codec_parameters, AVCodecParameters& audio_codec_parameters) {
    SetVideoAVCodecParameters(video_codec_parameters);
    SetAudioAVCodecParameters(audio_codec_parameters);
}

TRCodecParameters::~TRCodecParameters() {
}


void TRCodecParameters::Clear() {
    if (this->video_codec_parameters_ != NULL) {
        avcodec_parameters_free(&this->video_codec_parameters_);
        this->video_codec_parameters_ = NULL;
    }

    if (this->audio_codec_parameters_ != NULL) {
        avcodec_parameters_free(&this->audio_codec_parameters_);
        this->audio_codec_parameters_ = NULL;
    }
}

bool TRCodecParameters::IsVideoCodecParametersEmpty() {
    return IsCodecParametersNULL(this->video_codec_parameters_);
}

bool TRCodecParameters::IsAudioCodecParametersEmpty() {
    return IsCodecParametersNULL(this->audio_codec_parameters_);
}


void TRCodecParameters::SetVideoAVCodecParameters(AVCodecParameters& video_codec_parameters) {
    SetAVCodecParameters(&this->video_codec_parameters_, video_codec_parameters);
}

void TRCodecParameters::SetAudioAVCodecParameters(AVCodecParameters& audio_codec_parameters) {
    SetAVCodecParameters(&this->audio_codec_parameters_, audio_codec_parameters);
}

const AVCodecParameters* TRCodecParameters::GetVideoAVCodecParameters() {
    return this->video_codec_parameters_;
}

const AVCodecParameters* TRCodecParameters::GetAudioAVCodecParameters() {
    return this->audio_codec_parameters_;
}


TRCodecParameters& TRCodecParameters::operator=(TRCodecParameters& codec_parameters) {
    if (codec_parameters.video_codec_parameters_ != NULL) {
        this->SetVideoAVCodecParameters(*codec_parameters.video_codec_parameters_);
    }

    if (codec_parameters.audio_codec_parameters_ != NULL) {
        this->SetAudioAVCodecParameters(*codec_parameters.audio_codec_parameters_);
    }

    return *this;
}


void TRCodecParameters::SetAVCodecParameters(AVCodecParameters** codec_parameters, AVCodecParameters& copy_target_parameters) {
    if (*codec_parameters == NULL) {
        *codec_parameters = avcodec_parameters_alloc();
    }
    memset(*codec_parameters, 0x00, sizeof(**codec_parameters));

    memcpy(*codec_parameters, &copy_target_parameters, sizeof(copy_target_parameters));
 //   (*codec_parameters)->extradata      = NULL;
 //   (*codec_parameters)->extradata_size = 0;
}

bool TRCodecParameters::IsCodecParametersNULL(AVCodecParameters* codec_parameter) {
    if (codec_parameter == NULL) {
        return false;
    }

    return NULL;
}