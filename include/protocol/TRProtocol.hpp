#ifndef __TYRANNO_PROTOCOL_HEADER__
#define __TYRANNO_PROTOCOL_HEADER__

#include "TR_PROTOCOL_TYPE.hpp"

#include <cstring>

#define TR_PROTOCOL_VERSION 1

class TRProtocol {
public:
    explicit TRProtocol();
    virtual ~TRProtocol();

protected:
    TR_VERSION GetTRProtocolVersion();
};

#endif