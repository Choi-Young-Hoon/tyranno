#include "TRStreamIndex.hpp"


TRStreamIndex::TRStreamIndex()
: video_stream_index_(0), audio_stream_index_(0)
{}

TRStreamIndex::TRStreamIndex(int video_stream_index, int audio_stream_index) 
: video_stream_index_(video_stream_index), audio_stream_index_(audio_stream_index)
{}

TRStreamIndex::~TRStreamIndex()
{}


void TRStreamIndex::SetVideoStreamIndex(int video_stream_index) {
    this->video_stream_index_ = video_stream_index;
}

void TRStreamIndex::SetAudioStreamIndex(int audio_stream_index) {
    this->audio_stream_index_ = audio_stream_index;
}


int TRStreamIndex::GetVideoStreamIndex() {
    return this->video_stream_index_;
}

int TRStreamIndex::GetAudioStreamIndex() {
    return this->audio_stream_index_;
}