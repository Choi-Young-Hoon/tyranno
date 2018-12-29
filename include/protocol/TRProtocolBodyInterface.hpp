#ifndef __TYRANNO_PROTOCOL_BODY_INTERFACE_HEADER__
#define __TYRANNO_PROTOCOL_BODY_INTERFACE_HEADER__

#include "TRError.hpp"
#include "TRProtocol.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocolBodyInterface : public TRProtocol {
public:
    explicit TRProtocolBodyInterface();
    virtual ~TRProtocolBodyInterface();

public:
    virtual void marshal(TRByteBuffer* byte_buffer) = 0;
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error) = 0;
};


#endif