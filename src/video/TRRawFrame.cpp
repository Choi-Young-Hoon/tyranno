#include "TRRawFrame.hpp"

TRRawFrame::TRRawFrame() {
    this->frame_ = av_frame_alloc();
}

TRRawFrame::~TRRawFrame() {
    if (this->frame_ != NULL) {
        av_frame_unref(this->frame_);
    }
    av_frame_free(&this->frame_);
}


void TRRawFrame::Clear() {
    av_frame_unref(this->frame_);
}