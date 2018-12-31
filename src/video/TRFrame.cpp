#include "TRFrame.hpp"

TRFrame::TRFrame() {
    av_init_packet(&this->packet_);
}

TRFrame::~TRFrame() {
    if (this->packet_.data != NULL) {
        delete[] this->packet_.data;
    }
}


void TRFrame::Clear() {
    this->packet_.data = NULL;
    this->packet_.size = 0;
    av_packet_unref(&this->packet_);
}


void TRFrame::SetData(TRByteBuffer& byte_buffer) {
    Clear();

    this->packet_.data = new uint8_t[byte_buffer.GetLength()];
    if (this->packet_.data == NULL) {
        return;
    }

    memcpy(this->packet_.data, byte_buffer.GetData(), byte_buffer.GetLength());
    this->packet_.size = byte_buffer.GetLength();
}


void TRFrame::GetData(TRByteBuffer* byte_buffer) {
    if (this->packet_.data == NULL) {
        return;
    } 

    byte_buffer->SetData(this->packet_.data, this->packet_.size);
}