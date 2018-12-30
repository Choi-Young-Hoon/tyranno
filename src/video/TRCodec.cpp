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


void TRCodec::InitializeCodec(TRCodecID& codec_id, TRError* error) {
    InitializeVideoCodec(codec_id.GetVideoCodecID(), error);
    if(error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return;
    }

    InitializeAudioCodec(codec_id.GetAudioCodecID(), error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return;
    }
}

void TRCodec::InitializeCodec(TRVideo& video, TRError* error) {
    TRCodecID codec_id(video.GetVideoCodecID(), video.GetAudioCodecID());

    InitializeCodec(codec_id, error);
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


void TRCodec::InitializeVideoCodec(TR_CODEC_ID codec_id, TRError* error) {
    this->video_codec_ = createCodec(codec_id);
    if (this->video_codec_ != NULL) {
        this->video_codec_ctx_ = avcodec_alloc_context3(this->video_codec_);
    } else {
        this->video_codec_ctx_ = NULL;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}

void TRCodec::InitializeAudioCodec(TR_CODEC_ID codec_id, TRError* error) {
    this->audio_codec_ = createCodec(codec_id);
    if (this->audio_codec_ == NULL) {
        this->audio_codec_ctx_ = avcodec_alloc_context3(this->audio_codec_);
    } else {
        this->audio_codec_ctx_ = NULL;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}