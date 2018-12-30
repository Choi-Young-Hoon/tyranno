#ifndef __TYRANNO_TCP_CONNECTOR_HERADER__
#define __TYRANNO_TCP_CONNECTOR_HERADER__

#include "TRTcpEndPoint.hpp"
#include "TRTcpSocket.hpp"

class TRTcpConnector {
public:
    explicit TRTcpConnector();
    virtual ~TRTcpConnector();

public:
    TRTcpSocket ConnectServer(TRTcpEndPoint& end_point, TRError* error);
};

#endif