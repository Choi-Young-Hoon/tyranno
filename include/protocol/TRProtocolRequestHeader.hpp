#ifndef __TYRANNO_PROTOCOL_REQUEST_HEADER__
#define __TYRANNO_PROTOCOL_REQUEST_HEADER__

#include "TRProtocol.hpp"

extern "C" {
    struct _TR_PROTOCOL_REQUEST_HEADER {
        uint request_type_;
        uint8_t system_type_;
        uint16_t version_;
        uint session_;
    };
    typedef struct _TR_PROTOCOL_REQUEST_HEADER TR_PROTOCOL_REQUEST_HEADER;
};

class TRProtocolRequestHeader : public TRProtocol {
public:
    explicit TRProtocolRequestHeader();
    virtual ~TRProtocolRequestHeader();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

public:
    void Clear();

    void SetRequestType();
    void SetSystemType();
    void SetVersion();
    void SetSession();

    uint     GetRequestType();
    uint8_t  GetSystemType();
    uint16_t GetVersion();
    uint     GetSession();

private:
    TR_PROTOCOL_REQUEST_HEADER header_data_;
};

#endif
