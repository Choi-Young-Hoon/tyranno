#ifndef __TYRANNO_PROTOCOL_EXIT_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_EXIT_RESPONSE_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocolExitResponse : public TRProtocolBodyInterface {
public:
    explicit TRProtocolExitResponse();
    virtual ~TRProtocolExitResponse();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);
};

#endif