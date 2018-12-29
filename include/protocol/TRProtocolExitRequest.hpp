#ifndef __TYRANNO_PROTOCOL_EXIT_REQUEST_HEADER__
#define __TYRANNO_PROTOCOL_EXIT_REQUEST_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {
    struct _TR_PROTOCOL_EXIT_REQUEST {

    };
    typedef struct _TR_PROTOCOL_EXIT_REQUEST TR_PROTOCOL_EXIT_REQUEST;
};

class TRProtocolExitRequest : public TRProtocolBodyInterface {
public:
    explicit TRProtocolExitRequest();
    virtual ~TRProtocolExitRequest();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

    virtual void Clear();

private:
    TR_PROTOCOL_EXIT_REQUEST body_data_;
};
#endif