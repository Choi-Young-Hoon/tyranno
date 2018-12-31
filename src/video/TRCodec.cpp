#include "TRCodec.hpp"


TRCodec::TRCodec() {
    this->audio_codec_ = NULL;
    this->audio_codec_ctx_ = NULL;

    this->video_codec_ = NULL;
    this->video_codec_ctx_ = NULL;
}

TRCodec::~TRCodec() {
    if (this->video_codec_ctx_ != NULL) {
        avcodec_free_context(&this->video_codec_ctx_);
    }

    if (this->audio_codec_ctx_ != NULL) {
        avcodec_free_context(&this->audio_codec_ctx_);
    }
}


void TRCodec::InitializeCodec(TRCodecID& codec_id, TRCodecParameters& codec_parameter, TRError* error) {
    InitializeVideoCodec(codec_id.GetVideoCodecID(), codec_parameter, error);
    if(error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return;
    }

    InitializeAudioCodec(codec_id.GetAudioCodecID(), codec_parameter, error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return;
    }
}

void TRCodec::InitializeCodec(TRVideo& video, TRError* error) {
    TRCodecID codec_id = video.GetCodecID();
    TRCodecParameters codec_parameters = video.GetCodecParameters();

    InitializeCodec(codec_id, codec_parameters, error);
}

void TRCodec::SetVideoCodecParameter(const AVCodecParameters& codec_parameters) {
    avcodec_parameters_to_context(this->video_codec_ctx_, &codec_parameters);
    av_free(this->video_codec_ctx_->extradata);
//    this->video_codec_ctx_->extradata = NULL;
//    this->video_codec_ctx_->extradata_size = 0;
}

AVCodec* TRCodec::createCodec(TR_CODEC_ID codec_id) {
    TR_UNUSED(codec_id);

    return NULL;
}

    
void TRCodec::SetVideoCodecCtx(AVCodecContext* video_codec_ctx) {
    this->video_codec_ctx_ = video_codec_ctx;
}

void TRCodec::SetAudioCodecCtx(AVCodecContext* audio_codec_ctx) {
    this->audio_codec_ctx_ = audio_codec_ctx;
}

AVCodecContext* TRCodec::GetVideoCodecCtx() {
    return this->video_codec_ctx_;
}

AVCodecContext* TRCodec::GetAudioCodecCtx() {
    return this->audio_codec_ctx_;
}


void TRCodec::InitializeVideoCodec(TR_CODEC_ID codec_id, TRCodecParameters& codec_parameters,TRError* error) {
    InitializeCodec(codec_id, codec_parameters.GetVideoAVCodecParameters(), &this->video_codec_, &this->video_codec_ctx_, error);
}

void TRCodec::InitializeAudioCodec(TR_CODEC_ID codec_id, TRCodecParameters& codec_parameters, TRError* error) {
    InitializeCodec(codec_id, codec_parameters.GetAudioAVCodecParameters(), &this->audio_codec_, &this->audio_codec_ctx_, error);
}

void TRCodec::InitializeCodec(TR_CODEC_ID codec_id, const AVCodecParameters* codec_parameters, AVCodec** codec, AVCodecContext** codec_context, TRError* error) {
    *codec = createCodec(codec_id);
    if (*codec == NULL) {
        *codec_context = NULL;
        return;
    } 

    *codec_context = avcodec_alloc_context3(*codec);
    if (codec_context == NULL) {
        error->SetErrorValue(ERROR_DEFINE::MEMORY_ALLOC_FAILED, "codec context alloc failed");
        return;
    }

    if (codec_parameters != NULL) {
        avcodec_parameters_to_context(*codec_context, codec_parameters);
    }

    avcodec_open2(*codec_context, *codec, NULL);
    
    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}