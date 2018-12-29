#ifndef __TYRANNO_PROTOCOL_HEADER__
#define __TYRANNO_PROTOCOL_HEADER__

#include "TRError.hpp"
#include "util/TRByteBuffer.hpp"

class TRProtocol {
public:
    enum _ERROR_DEFINE {
        SUCCESS = 0,

        MEMORY_ALLOC_FAILED,
        UNMARSHAL_DATA_SIZE_NOT_ENOUGH,
    };
    typedef enum _ERROR_DEFINE ERROR_DEFINE;

public:
    explicit TRProtocol();
    virtual ~TRProtocol();

public:
    virtual void marshal(TRByteBuffer* byte_buffer) = 0;
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error) = 0;
};

#endif