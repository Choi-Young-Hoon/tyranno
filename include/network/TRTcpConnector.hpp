#ifndef __TYRANNO_TCP_CONNECTOR_HERADER__
#define __TYRANNO_TCP_CONNECTOR_HERADER__

#include "TRTcpEndPoint.hpp"
#include "TRTcpSocket.hpp"

class TRTcpConnector {
public:
    enum _ERROR_DEFINE {
        SUCCESS = 0,

        SERVER_CONNECT_FAILED,
    };
    typedef enum _ERROR_DEFINE ERROR_DEFINE;

public:
    explicit TRTcpConnector();
    virtual ~TRTcpConnector();

public:
    TRTcpSocket ConnectServer(TRTcpEndPoint& end_point, TRError* error);
};

#endif