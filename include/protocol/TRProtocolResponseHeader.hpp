#ifndef __TYRANNO_PROTOCOL_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_RESPONSE_HEADER__

#include "TRProtocolHeaderInterface.hpp"

extern "C" {
    struct _TR_PROTOCOL_RESPONSE_DATA {
        uint request_type;
        uint result_code;
        uint error_message_length;
    };
    typedef struct _TR_PROTOCOL_RESPONSE_DATA TR_PROTOCOL_RESPONSE_DATA;

    struct _TR_PROTOCOL_RESPONSE_HEADER {
        TR_PROTOCOL_RESPONSE_DATA data;
        char* error_message;
    };
    typedef struct _TR_PROTOCOL_RESPONSE_HEADER TR_PROTOCOL_RESPONSE_HEADER;
};

class TRProtocolResponseHeader : public TRProtocolHeaderInterface {
public:
    explicit TRProtocolResponseHeader();
    virtual ~TRProtocolResponseHeader();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

public:
    void Clear();

    // set
    void SetRequestType(uint request_type);
    void SetResultCode(uint result_code);
    void SetErrorMessage(const char* error_message);
    void SetErrorMessage(std::string& error_message);

    // get 
    uint GetRequestType();
    uint GetResultCode();
    uint GetErrorMessageLength();
    std::string GetErrorMessage();

private:
    int GetRequestType(TRByteBuffer& byte_buffer);
    int GetResultCode(TRByteBuffer& byte_buffer);
    int GetErrorMessageLength(TRByteBuffer& byte_buffer);

private:
    TR_PROTOCOL_RESPONSE_HEADER header_data_;
};

#endif