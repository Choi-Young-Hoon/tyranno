#include "TREncoder.hpp"


TREncoder::TREncoder()
: codec_(NULL)
{}

TREncoder::~TREncoder() {
    if (codec_ != NULL) {
        delete this->codec_;
    }
}


void TREncoder::SetCodec(TRCodec* codec) {
    if (this->codec_ != NULL) {
        delete this->codec_;
    }
    this->codec_ = codec;
}

void TREncoder::Encode(TRRawFrame& decoded_frame, TRFrame* encode_frame, TRError* error) {
    int ret = avcodec_send_frame(this->codec_->video_codec_ctx_, decoded_frame.frame_);
    if (ret < 0) {
        error->SetErrorValue(ERROR_DEFINE::ENCODING_DATA_TO_ENCODER_COPY_FAILED, "Encoding data to decoder copy failed");
        return;
    }

    ret = 0;
    while (ret >= 0) {
        ret = avcodec_receive_packet(this->codec_->video_codec_ctx_, &encode_frame->packet_);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
            break;
        } else if (ret < 0) {
            error->SetErrorValue(ERROR_DEFINE::ENCODING_FAILED, "Encoding failed");
            return;
        }
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}