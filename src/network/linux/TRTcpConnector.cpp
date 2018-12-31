#ifdef __linux__

#include "TRTcpConnector.hpp"

#include <cstdio>
#include <cstring>
#include <cerrno>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

TRTcpConnector::TRTcpConnector()
{}

TRTcpConnector::~TRTcpConnector()
{}


TRTcpSocket TRTcpConnector::ConnectServer(TRTcpEndPoint& end_point, TRError* error) {
    TRTcpSocket ret_socket;

    ret_socket.CreateSocket(error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return ret_socket;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0x00, sizeof(server_addr));
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(end_point.GetPort());
    server_addr.sin_addr.s_addr = inet_addr(end_point.GetIpAddress().c_str());
    
    int ret = connect((int)ret_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        error->SetErrorValue(ERROR_DEFINE::SERVER_CONNECT_FAILED, strerror(errno));
        return ret_socket;
    }

    ret_socket.SetEndPoint(end_point);
    error->SetErrorCode(ERROR_DEFINE::SUCCESS);

    return ret_socket;
}

#endif