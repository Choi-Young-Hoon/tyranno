#ifndef __TYRANNO_PROTOCOL_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_RESPONSE_HEADER__

#include "TRError.hpp"
#include "util/TRByteBuffer.hpp"

#include <string>

class TRProtocolResponseHeader {
public:
    explicit TRProtocolResponseHeader();
    virtual ~TRProtocolResponseHeader();


protected:
    virtual void marshal(TRByteBuffer* byte_buffer, TRError* error);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

private:
    uint result_code_;
    uint error_message_length;
    std::string error_message;
};
#endif