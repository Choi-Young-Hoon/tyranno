#include "TRDecoder.hpp"


TRDecoder::TRDecoder()
: codec_(NULL)
{}

TRDecoder::~TRDecoder() {
    if (this->codec_ != NULL) {
        delete this->codec_;
    }
}


void TRDecoder::SetCodec(TRCodec* codec) {
    if (this->codec_ != NULL) {
        delete this->codec_;
    }
    this->codec_ = codec;
}

void TRDecoder::Decode(TRFrame& encoded_frame, TRRawFrame* decode_frame, TRError* error) {
    int ret = avcodec_send_packet(this->codec_->video_codec_ctx_, &encoded_frame.packet_);
    if (ret < 0) {
        error->SetErrorValue(ERROR_DEFINE::DECODING_DATA_TO_DECODER_COPY_FAILED, "Decoding data to decoder copy failed");
        return;
    }

    ret = 0;
    while (ret >= 0) {
        ret = avcodec_receive_frame(this->codec_->video_codec_ctx_, decode_frame->frame_);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
            break;
        } else if (ret < 0) {
            error->SetErrorValue(ERROR_DEFINE::DECODING_FAILED, "Decoding failed");
            return;
        }
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}