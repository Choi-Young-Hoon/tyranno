#ifndef __TYRANNO_PROTOCOL_TRANSCODING_HEADER__
#define __TYRANNO_PROTOCOL_TRANSCODING_HEADER__

#include "TRError.hpp"
#include "TRProtocolBodyInterface.hpp"
#include "util/TRByteBuffer.hpp"

extern "C" {

};

class TRProtocolTranscoding : public TRProtocolBodyInterface {
public:
    explicit TRProtocolTranscoding();
    virtual ~TRProtocolTranscoding();

public:
    virtual void marshal(TRByteBuffer* byte_buffer);
    virtual void unmarshal(TRByteBuffer& byte_buffer, TRError* error);

private:

};

#endif