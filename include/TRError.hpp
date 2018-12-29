#ifndef __TRANNO_ERROR_HEADER__
#define __TRANNO_ERROR_HEADER__

#include "TR_DEFINE.hpp"

#include <string>

class TRError {
public:
    explicit TRError() 
    : error_code_(0)
    {}
    virtual ~TRError()
    {}


public:
    // get
    int         GetErrorCode()    { return this->error_code_; }
    std::string GetErrorMessage() { return this->error_message_; }

    // set
    void SetErrorValue(int error_code, std::string& error_message) {
        SetErrorCode(error_code);
        SetErrorMessage(error_message);
    }

    void SetErrorValue(int error_code, const char* error_message) {
        SetErrorCode(error_code);
        SetErrorMessage(error_message);
    }

    void SetErrorCode(int error_code) { this->error_code_ = error_code; }
    void SetErrorMessage(std::string& error_message) { this->error_message_ = error_message; }
    void SetErrorMessage(const char* error_message)  { this->error_message_ = error_message; }

private:
    int error_code_;
    std::string error_message_;
};

#endif
