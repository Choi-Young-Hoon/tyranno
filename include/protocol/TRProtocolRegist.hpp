#ifndef __TYRANNO_PROTOCOL_REGIST_HEADER__
#define __TYRANNO_PROTOCOL_REGIST_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {

};

class TRProtocolRegist : public TRProtocolBodyInterface {
public:
    explicit TRProtocolRegist();
    virtual ~TRProtocolRegist();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

private:

};

#endif