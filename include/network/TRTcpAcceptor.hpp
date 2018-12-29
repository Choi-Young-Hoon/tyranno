#ifndef __TYRANNO_TCP_ACCEPTOR_HEADER__
#define __TYRANNO_TCP_ACCEPTOR_HEADER__

#include "TRError.hpp"
#include "TRTcpSocket.hpp"
#include "TRTcpEndPoint.hpp"

class TRTcpAcceptor {
public:
    enum _ERROR_DEFINE {
        SUCCESS = 0,    
        PORT_INFO_EMPTY,
        SOCKET_BIND_FAILED,
        SOCKET_LISTEN_FAILED,
        CLIENT_ACCEPT_FAILED,
    };
    typedef enum _ERROR_DEFINE ERROR_DEFINE;


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
