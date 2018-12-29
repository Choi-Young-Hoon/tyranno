#ifndef __TYRANNO_PROTOCOL_REGIST_REQUEST_HEADER__
#define __TYRANNO_PROTOCOL_REGIST_REQUEST_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {

};

class TRProtocolRegistRequest : public TRProtocolBodyInterface {
public:
    explicit TRProtocolRegistRequest();
    virtual ~TRProtocolRegistRequest();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

private:

};

#endif