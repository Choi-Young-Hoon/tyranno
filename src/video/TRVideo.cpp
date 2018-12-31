#include "TRVideo.hpp"

TRVideo::TRVideo() {
    this->format_ctx_ = NULL;
}

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
    int video_stream_index = av_find_best_stream(this->format_ctx_, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    int audio_stream_index = av_find_best_stream(this->format_ctx_, AVMEDIA_TYPE_AUDIO, -1, video_stream_index, NULL, 0);
    this->stream_index_.SetVideoStreamIndex(video_stream_index);
    this->stream_index_.SetAudioStreamIndex(audio_stream_index);

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

    int ret = av_read_frame(this->format_ctx_, &frame->packet_);
    if (ret == AVERROR_EOF) {
        error->SetErrorCode(ERROR_DEFINE::READ_FRAME_EOF);
        return true;
    } else if (ret < 0) {
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

TRCodecID TRVideo::GetCodecID() {
    TR_CODEC_ID video_codec_id = GetCodecID(this->stream_index_.GetVideoStreamIndex());
    TR_CODEC_ID audio_codec_id = GetCodecID(this->stream_index_.GetAudioStreamIndex());

    return TRCodecID(video_codec_id, audio_codec_id);
}

TRStreamIndex TRVideo::GetStreamIndex() {
    return this->stream_index_;
}

TRCodecParameters TRVideo::GetCodecParameters() {
    TRCodecParameters ret_codec_parameters;
    if (IsOpen() == false) {
        return ret_codec_parameters;
    }

    AVCodecParameters* video_codec_parameters = GetAVCodecParameters(this->stream_index_.GetVideoStreamIndex());
    if (video_codec_parameters != NULL) {
        ret_codec_parameters.SetVideoAVCodecParameters(*video_codec_parameters);
    }

    AVCodecParameters* audio_codec_parameters = GetAVCodecParameters(this->stream_index_.GetAudioStreamIndex());
    if (audio_codec_parameters != NULL) {
        ret_codec_parameters.SetAudioAVCodecParameters(*audio_codec_parameters);
    }

    return ret_codec_parameters;
}

TR_CODEC_ID TRVideo::GetCodecID(int stream_index) {
    if (IsOpen() == false || stream_index < 0) {
        return AV_CODEC_ID_NONE;
    }

    return this->format_ctx_->streams[stream_index]->codecpar->codec_id;
}

AVCodecParameters* TRVideo::GetAVCodecParameters(int stream_index) {
    if (IsOpen() == false || stream_index < 0) {
        return NULL;
    }

    return this->format_ctx_->streams[stream_index]->codecpar;
}