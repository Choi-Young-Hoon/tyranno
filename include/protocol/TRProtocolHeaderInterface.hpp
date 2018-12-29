#ifndef __TYRANNO_PROTOCOL_HEADER_HEADER__
#define __TYRANNO_PROTOCOL_HEADER_HEADER__

#include "TRError.hpp"
#include "TRProtocol.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocolHeaderInterface : public TRProtocol {
public:
    explicit TRProtocolHeaderInterface();
    virtual ~TRProtocolHeaderInterface();

public:
    virtual void marshal(TRByteBuffer* byte_buffer) = 0;
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error) = 0;

    virtual void Clear();
};

#endif