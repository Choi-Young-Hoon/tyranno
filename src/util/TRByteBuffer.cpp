#include "TRByteBuffer.hpp"

#include <cstring>

TRByteBuffer::TRByteBuffer() {
    this->buffer_.reserve(0);
}

TRByteBuffer::TRByteBuffer(unsigned char* data, int length) {
    SetData(data, length);
}

TRByteBuffer::TRByteBuffer(const char* data) {
    SetData(data);
}

TRByteBuffer::~TRByteBuffer() {
    Clear();
}


void TRByteBuffer::Clear() {
    this->buffer_.clear();
    this->buffer_.reserve(0);
}

bool TRByteBuffer::IsEmpty() {
    if (this->buffer_.size() != 0) {
        return false;
    }
    return true;
}

const unsigned char* TRByteBuffer::GetData() {
    return &this->buffer_[0];
}

int TRByteBuffer::GetLength() {
    return this->buffer_.size();
}


void TRByteBuffer::SetData(unsigned char* data, int length) {
    this->buffer_.reserve(length);
    this->buffer_.insert(this->buffer_.begin(), &data[0], &data[length]);
}

void TRByteBuffer::SetData(const char* data) {
    int data_length = strlen(data) + 1;
    this->buffer_.reserve(data_length);
    this->buffer_.insert(this->buffer_.begin(), &data[0], &data[data_length]);
}


TRByteBuffer& TRByteBuffer::Append(TRByteBuffer& buffer) {
    return Append(&buffer.buffer_[0], buffer.buffer_.size());
}

TRByteBuffer& TRByteBuffer::Append(unsigned char* data, int length) {
    this->buffer_.insert(this->buffer_.end(), &data[0], &data[length]);
    return *this;
}

TRByteBuffer TRByteBuffer::Sub(int start_index, int end_index) {
    return TRByteBuffer(&this->buffer_[start_index], end_index - start_index + 1);
}

unsigned char TRByteBuffer::operator[](int index) {
    return this->buffer_[index];
}

TRByteBuffer& TRByteBuffer::operator+=(TRByteBuffer& buffer) {
    return this->Append(buffer);    
}

TRByteBuffer& TRByteBuffer::operator+(TRByteBuffer& buffer) {
    return this->Append(buffer);
}
