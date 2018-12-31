#include "TRVideoWriter.hpp"

TRVideoWriter::TRVideoWriter() {
    this->format_ctx_ = NULL;
}

TRVideoWriter::~TRVideoWriter() {
    Close();
}


void TRVideoWriter::Open(std::string& file_name, TRError* error) {
    Open(file_name.c_str(), error);
}

void TRVideoWriter::Open(const char* file_name, TRError* error) {


    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}

void TRVideoWriter::Close() {
    if (this->format_ctx_ != NULL) {
        if (this->format_ctx_ && !(this->format_ctx_->oformat->flags & AVFMT_NOFILE)) {
            avio_closep(&this->format_ctx_->pb);
        }
        
        avformat_free_context(this->format_ctx_);
    }

    this->format_ctx_ = NULL;
}


bool TRVideoWriter::IsOpen() {
    if (this->format_ctx_ == NULL) {
        return false;
    }

    return true;
}


bool TRVideoWriter::WriteFrame(TRFrame* frame, TRError* error) {

    return true;
}