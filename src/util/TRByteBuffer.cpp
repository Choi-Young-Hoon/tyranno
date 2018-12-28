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

TRByteBuffer::~TRByteBuffer() 
{}


const unsigned char* TRByteBuffer::GetData() {
    return &this->buffer_[0];
}

int TRByteBuffer::GetLength() {
    return this->buffer_.size();
}


void TRByteBuffer::SetData(unsigned char* data, int length) {
    this->buffer_.reserve(length);
    memcpy(&this->buffer_[0], data, length);
}

void TRByteBuffer::SetData(const char* data) {
    this->buffer_.reserve(strlen(data) + 1);
    memcpy(&this->buffer_[0], data, strlen(data) + 1);
}


TRByteBuffer& TRByteBuffer::Append(TRByteBuffer& buffer) {
    return Append(&buffer.buffer_[0], buffer.buffer_.size());
}

TRByteBuffer& TRByteBuffer::Append(unsigned char* data, int length) {
    std::vector<unsigned char> temp_array;
    temp_array.reserve(length);
    memcpy(&temp_array[0], data, length);
    this->buffer_.insert(this->buffer_.end(), temp_array.begin(), temp_array.end());
    
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
