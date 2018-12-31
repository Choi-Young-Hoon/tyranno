#ifdef __linux__

#include "TRTcpAcceptor.hpp"

#include <errno.h>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

TRTcpAcceptor::TRTcpAcceptor() 
: port_(0)
{}

TRTcpAcceptor::~TRTcpAcceptor()
{}


TRTcpSocket TRTcpAcceptor::AcceptClient(TRTcpEndPoint& end_point, TRError* error) {
    TRTcpSocket ret_socket;

    SocketBinding(end_point, error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return ret_socket;
    }

    struct sockaddr_in client_addr;
    memset(&client_addr, 0x00, sizeof(client_addr));

    socklen_t client_addr_size = sizeof(client_addr_size);
    int client_socket = accept((int)socket_, (struct sockaddr*)&client_addr, &client_addr_size);
    if (client_socket == -1) {
        error->SetErrorValue(ERROR_DEFINE::CLIENT_ACCEPT_FAILED, strerror(errno));
        return ret_socket;
    }

    char client_ip_address[INET_ADDRSTRLEN] = {0, };
    inet_ntop(PF_INET, &client_addr.sin_addr, client_ip_address, INET_ADDRSTRLEN);

    TRTcpEndPoint ret_socket_end_point;
    ret_socket_end_point.SetIpAddress(client_ip_address);
    ret_socket_end_point.SetProtocolVersion(end_point.GetProtocolVersion());

    ret_socket.SetEndPoint(ret_socket_end_point);
    ret_socket.SetRawSocketDescriptor(client_socket);
    error->SetErrorCode(ERROR_DEFINE::SUCCESS);

    return ret_socket;
}

void TRTcpAcceptor::SocketBinding(TRTcpEndPoint& end_point, TRError* error) {
    if (this->port_ == 0) {
        error->SetErrorValue(ERROR_DEFINE::PORT_INFO_EMPTY, "Port info empty");
        return;
    }
   
   socket_.CloseSocket();
   socket_.CreateSocket(error);
   if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
       return ;
   }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0x00, sizeof(server_addr));
    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(end_point.GetPort());

    int ret = bind((int)socket_, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
    if (ret == -1) {
        error->SetErrorValue(ERROR_DEFINE::SOCKET_BIND_FAILED, strerror(errno));
        return;
    }

    ret = listen((int)socket_, 5);
    if (ret == -1) {
        error->SetErrorValue(ERROR_DEFINE::SOCKET_LISTEN_FAILED, strerror(errno));
        return ;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}

#endif
