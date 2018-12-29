#ifndef __TYRANNO_PROTOCOL_REGIST_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_REGIST_RESPONSE_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocolRegistResponse : public TRProtocolBodyInterface {
public:
    explicit TRProtocolRegistResponse();
    virtual ~TRProtocolRegistResponse();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);
};

#endif