#include "TRCodecID.hpp"


TRCodecID::TRCodecID()
: video_codec_id_(AV_CODEC_ID_NONE)
, audio_codec_id_(AV_CODEC_ID_NONE)
{}

TRCodecID::TRCodecID(TR_CODEC_ID video_codec_id, TR_CODEC_ID audio_codec_id)
: video_codec_id_(video_codec_id)
, audio_codec_id_(audio_codec_id)
{}

TRCodecID::~TRCodecID()
{}


void TRCodecID::SetVideoCodecID(TR_CODEC_ID video_codec_id) {
    this->video_codec_id_ = video_codec_id;
}

void TRCodecID::SetAudioCodecID(TR_CODEC_ID audio_codec_id) {
    this->audio_codec_id_ = audio_codec_id;
}


TR_CODEC_ID TRCodecID::GetVideoCodecID() {
    return this->video_codec_id_;
}

TR_CODEC_ID TRCodecID::GetAudioCodecID() {
    return this->audio_codec_id_;
}