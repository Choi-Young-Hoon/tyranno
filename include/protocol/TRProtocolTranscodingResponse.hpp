#ifndef __TYRANNO_PROTOCOL_TRANSCODING_RESPONSE_HEADER__
#define __TYRANNO_PROTOCOL_TRANSCODING_RESPONSE_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {
    struct _TR_PROTOCOL_TRANSCODING_RESPONSE {

    };
    typedef struct _TR_PROTOCOL_TRANSCODING_RESPONSE TR_PROTOCOL_TRANSCODING_RESPONSE;
};

class TRProtocolTranscodingResponse : public TRProtocolBodyInterface {
public:
    explicit TRProtocolTranscodingResponse();
    virtual ~TRProtocolTranscodingResponse();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

    virtual void Clear();
    
private:
    TR_PROTOCOL_TRANSCODING_RESPONSE body_data_;
};

#endif