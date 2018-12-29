#ifndef __TYRANNO_PROTOCOL_REQUEST_HEADER__
#define __TYRANNO_PROTOCOL_REQUEST_HEADER__

#include "TRError.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocolRequestHeader {
public:
    explicit TRProtocolRequestHeader();
    virtual ~TRProtocolRequestHeader();


protected:
    virtual void marshal(TRByteBuffer* byte_buffer, TRError* error);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

private:
    uint request_type_;
    uint8_t system_type_;
    uint16_t version_;
    uint session_;
};

#endif
