#include "TRCodec.hpp"

TRCodec* TRCodec::create(TRVideo& video, TRError* error) {
    TRCodec* ret_codec = new TRCodec();
    if (ret_codec == NULL) {
        error->SetErrorValue(TRCodec::MEMORY_ALLOC_FAILED, "codec memory alloc is NULL");
        return NULL;
    }

    ret_codec->InitializeCodec(video, error);
    if (error->GetErrorCode() != TRCodec::SUCCESS) {
        delete ret_codec;
        return NULL;
    }

    return ret_codec;
}

TRCodec::TRCodec()
: audio_codec_(NULL), audio_codec_ctx_(NULL)
, video_codec_(NULL), video_codec_ctx_(NULL)
{}

TRCodec::~TRCodec()
{}


void TRCodec::InitializeCodec(TRVideo& video, TRError* error) {
    InitializeVideoCodec(video, error);
    if(error->GetErrorCode() != TRCodec::SUCCESS) {
        return;
    }

    InitializeAudioCodec(video, error);
    if (error->GetErrorCode() != TRCodec::SUCCESS) {
        return;
    }
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


void TRCodec::InitializeVideoCodec(TRVideo& video, TRError* error) {
   this->video_codec_ = createCodec(video.GetVideoCodecID());
    if (this->video_codec_ == NULL) {
        error->SetErrorValue(TRCodec::NOT_FOUND_VIDEO_CODEC, "Not found video codec");
        return;
    }
    this->video_codec_ctx_ = avcodec_alloc_context3(this->video_codec_);
}

void TRCodec::InitializeAudioCodec(TRVideo& video, TRError* error) {
    this->audio_codec_ = createCodec(video.GetAudioCodecID());
    if (this->audio_codec_ == NULL) {
        error->SetErrorValue(TRCodec::NOT_FOUND_AUDIO_CODEC, "Not found audio codec");
        return;
    }
    this->audio_codec_ctx_ = avcodec_alloc_context3(this->audio_codec_);
}