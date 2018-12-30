#include "TRVideo.hpp"

TRVideo::TRVideo() 
: format_ctx_(NULL)
{}

TRVideo::~TRVideo() {
    Close();
}


void TRVideo::Open(std::string& file_name, TRError* error) {
    Open(file_name.c_str(), error);
}

void TRVideo::Open(const char* file_name, TRError* error) {
    int file_open_ret = avformat_open_input(&this->format_ctx_, file_name, NULL, NULL);
    if (file_open_ret < 0) {
        error->SetErrorValue(ERROR_DEFINE::FILE_OPEN_FAILED, "Cannot open file");
        return;
    }

    int file_stream_info_ret = avformat_find_stream_info(this->format_ctx_, NULL);
    if (file_stream_info_ret < 0) {
        error->SetErrorValue(ERROR_DEFINE::STREAM_INFO_NOT_FOUND, "Not found stream info");
        return;
    }
    this->video_stream_index_ = av_find_best_stream(this->format_ctx_, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    this->audio_stream_index_ = av_find_best_stream(this->format_ctx_, AVMEDIA_TYPE_AUDIO, -1, this->video_stream_index_, NULL, 0);

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}

void TRVideo::Close() {
    if (IsOpen() == true) {
        avformat_close_input(&this->format_ctx_);
    }
    this->format_ctx_ = NULL;
}

bool TRVideo::IsOpen() {
    if (this->format_ctx_ == NULL) {
        return false;
    }
    return true;
}


bool TRVideo::ReadFrame(TRFrame* frame, TRError* error) {
    if (!IsOpen()) {
        error->SetErrorValue(ERROR_DEFINE::FILE_NOT_OPENED, "File not opend");
        return false;
    }
    frame->Clear();

    int read_frame_ret = av_read_frame(this->format_ctx_, &frame->packet_);
    if (read_frame_ret <= 0) {
        error->SetErrorValue(ERROR_DEFINE::READ_FRAME_FAILED, "Read failed");
        return false;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
    return true;
}

uint TRVideo::GetStreamsCount() {
    if (IsOpen() == false) {
        return 0;
    }

    return this->format_ctx_->nb_streams;
}

TR_CODEC_ID TRVideo::GetVideoCodecID() {
    return GetCodecID(this->video_stream_index_);
}

TR_CODEC_ID TRVideo::GetAudioCodecID() {
    return GetCodecID(this->audio_stream_index_);
}

TR_CODEC_ID TRVideo::GetCodecID(int stream_index) {
    if (IsOpen() == false) {
        return AV_CODEC_ID_NONE;
    }

    return this->format_ctx_->streams[stream_index]->codecpar->codec_id;
}