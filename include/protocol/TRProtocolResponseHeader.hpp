#ifndef __TYRANNO_PROTOCOL_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_RESPONSE_HEADER__

#include "TRProtocolHeaderInterface.hpp"

extern "C" {
    struct _TR_PROTOCOL_RESPONSE_DATA {
        TR_REQUEST_TYPE request_type;
        TR_RESULT_CODE result_code;
        TR_ERROR_LENGTH error_message_length;
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

    virtual void Clear();
    
public:
    // set
    void SetRequestType(TR_REQUEST_TYPE request_type);
    void SetResultCode(TR_RESULT_CODE result_code);
    void SetErrorMessage(const char* error_message);
    void SetErrorMessage(std::string& error_message);

    // get 
    TR_REQUEST_TYPE GetRequestType();
    TR_RESULT_CODE  GetResultCode();
    TR_ERROR_LENGTH GetErrorMessageLength();
    std::string     GetErrorMessage();

private:
    TR_REQUEST_TYPE GetRequestType(TRByteBuffer& byte_buffer);
    TR_RESULT_CODE  GetResultCode(TRByteBuffer& byte_buffer);
    TR_ERROR_LENGTH GetErrorMessageLength(TRByteBuffer& byte_buffer);

private:
    TR_PROTOCOL_RESPONSE_HEADER header_data_;
};

#endif