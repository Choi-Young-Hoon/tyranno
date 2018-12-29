#ifndef __TYRANNO_PROTOCOL_REQUEST_HEADER__
#define __TYRANNO_PROTOCOL_REQUEST_HEADER__

#include "TRProtocolHeaderInterface.hpp"

extern "C" {
    struct _TR_PROTOCOL_REQUEST_HEADER {
        TR_REQUEST_TYPE request_type;
        TR_SYSTEM_TYPE system_type;
        TR_VERSION version;
        TR_SESSION session;
    };
    typedef struct _TR_PROTOCOL_REQUEST_HEADER TR_PROTOCOL_REQUEST_HEADER;
};

class TRProtocolRequestHeader : public TRProtocolHeaderInterface {
public:
    explicit TRProtocolRequestHeader();
    virtual ~TRProtocolRequestHeader();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);
    
    virtual void Clear();

public:
    // set
    void SetRequestType(TR_REQUEST_TYPE request_type);
    void SetSystemType(TR_SYSTEM_TYPE system_type);
    void SetSession(TR_SESSION session);

    // get
    TR_REQUEST_TYPE GetRequestType();
    TR_SYSTEM_TYPE  GetSystemType();
    TR_VERSION      GetVersion();
    TR_SESSION      GetSession();

private:
    TR_PROTOCOL_REQUEST_HEADER header_data_;
};

#endif
