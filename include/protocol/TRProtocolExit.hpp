#ifndef __TYRANNO_PROTOCOL_EXIT_HEADER__
#define __TYRANNO_PROTOCOL_EXIT_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {

};

class TRProtocolExit : public TRProtocolBodyInterface {
public:
    explicit TRProtocolExit();
    virtual ~TRProtocolExit();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

private:

};
#endif