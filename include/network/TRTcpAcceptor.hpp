#ifndef __TYRANNO_TCP_ACCEPTOR_HEADER__
#define __TYRANNO_TCP_ACCEPTOR_HEADER__

#include "TRError.hpp"
#include "TRTcpSocket.hpp"
#include "TRTcpEndPoint.hpp"

class TRTcpAcceptor {
public:
    explicit TRTcpAcceptor();
    virtual ~TRTcpAcceptor();

public:
    TRTcpSocket AcceptClient(TRTcpEndPoint& end_point, TRError* error);

private:
    void SocketBinding(TRTcpEndPoint& end_point ,TRError* error);

private:
    int port_;

    TRTcpSocket socket_;
};

#endif
