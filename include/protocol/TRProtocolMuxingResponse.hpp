#ifndef __TYRANNO_PROTOCOL_MUXING_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_MUXING_RESPONSE_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocolMuxingResponse : public TRProtocolBodyInterface {
public:
    explicit TRProtocolMuxingResponse();
    virtual ~TRProtocolMuxingResponse();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);
};

#endif