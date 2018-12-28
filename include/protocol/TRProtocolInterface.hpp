#ifndef __TYRANNO_PROTOCOL_INTERFACE_HEADER__
#define __TYRANNO_PROTOCOL_INTERFACE_HEADER__

class TRProtocolInterface {
public:
    explicit TRProtocolInterface();
    virtual ~TRProtocolInterface();


public:
    virtual bool marshal()   = 0;
    virtual bool unmarshal() = 0;
};

#endif
