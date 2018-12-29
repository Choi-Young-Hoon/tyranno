#ifndef __TYRANNO_PROTOCOL_REGIST_REQUEST_HEADER__
#define __TYRANNO_PROTOCOL_REGIST_REQUEST_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {
    struct _TR_PROTOCOL_REGIST_REQUEST {
        TR_VERSION system_version;
    };
    typedef struct _TR_PROTOCOL_REGIST_REQUEST TR_PROTOCOL_REGIST_REQUEST; 
};

class TRProtocolRegistRequest : public TRProtocolBodyInterface {
public:
    explicit TRProtocolRegistRequest();
    virtual ~TRProtocolRegistRequest();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

    virtual void Clear();
    
public:
    // set
    void SetSystemVersion(TR_VERSION system_version);

    // get
    TR_VERSION GetSystemVersion();

private:
    TR_PROTOCOL_REGIST_REQUEST body_data_;
};

#endif