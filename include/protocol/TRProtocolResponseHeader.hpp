#ifndef __TYRANNO_PROTOCOL_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_RESPONSE_HEADER__

#include "TRProtocol.hpp"

extern "C" {
    struct _TR_PROTOCOL_RESPONSE_HEADER {
        uint result_code_;
        uint error_message_length;
        char* error_message;
    };
    typedef struct _TR_PROTOCOL_RESPONSE_HEADER TR_PROTOCOL_RESPONSE_HEADER;
};

class TRProtocolResponseHeader : public TRProtocol {
public:
    explicit TRProtocolResponseHeader();
    virtual ~TRProtocolResponseHeader();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

public:
    void Clear();

    // set
    void SetResultCode(uint result_code);
    void SetErrorMessage(const char* error_message);
    void SetErrorMessage(std::string& error_message);

    // get 
    uint GetResultCode();
    uint GetErrorMessageLength();
    std::string GetErrorMessage();

private:
    TR_PROTOCOL_RESPONSE_HEADER header_data_;
};

#endif