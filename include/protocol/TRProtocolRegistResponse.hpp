#ifndef __TYRANNO_PROTOCOL_REGIST_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_REGIST_RESPONSE_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {
    struct _TR_PROTOCOL_REGIST_RESPONSE {
        TR_SESSION session;
    };
    typedef struct _TR_PROTOCOL_REGIST_RESPONSE TP_PROTOCOL_REGIST_RESPONSE;
};

class TRProtocolRegistResponse : public TRProtocolBodyInterface {
public:
    explicit TRProtocolRegistResponse();
    virtual ~TRProtocolRegistResponse();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

    virtual void Clear();

public:
    // set
    void SetSession(TR_SESSION session);
    
    // get
    TR_SESSION GetSession();

private:
    TP_PROTOCOL_REGIST_RESPONSE body_data_;
};

#endif