#include "TRFrame.hpp"

TRFrame::TRFrame() {
    Clear();
}

TRFrame::~TRFrame()
{}


void TRFrame::Clear() {
    av_init_packet(&this->packet_);

    this->packet_.data = NULL;
    this->packet_.size = 0;
}

void TRFrame::GetByteBuffer(TRByteBuffer* byte_buffer) {
    if (this->packet_.data == NULL) {
        return;
    } 

    byte_buffer->SetData(this->packet_.data, this->packet_.size);
}