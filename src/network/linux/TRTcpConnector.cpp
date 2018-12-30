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
    TRTcpSocket return_socket;

    return_socket.CreateSocket(error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return return_socket;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0x00, sizeof(server_addr));
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(end_point.GetPort());
    server_addr.sin_addr.s_addr = inet_addr(end_point.GetIpAddress().c_str());
    
    int connect_ret = connect((int)return_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (connect_ret == -1) {
        error->SetErrorValue(ERROR_DEFINE::SERVER_CONNECT_FAILED, strerror(errno));
        return return_socket;
    }

    return_socket.SetEndPoint(end_point);
    error->SetErrorCode(ERROR_DEFINE::SUCCESS);

    return return_socket;
}

#endif