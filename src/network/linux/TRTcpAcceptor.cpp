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

TRTcpAcceptor::TRTcpAcceptor(int port) 
: port_(port)
{}

TRTcpAcceptor::~TRTcpAcceptor()
{}


void TRTcpAcceptor::SocketBinding(TRError* error) {
    if (this->port_ == 0) {
        error->SetErrorValue(ERROR_DEFINE::PORT_INFO_EMPTY, "Port info empty");
        return;
    }
   
    if (!socket_.IsCreated()) {
        socket_.CreateSocket(error);
        if (error->GetErrorCode() != TRTcpSocket::SUCCESS) {
            return;
        }
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0x00, sizeof(server_addr));
    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(10000);

    int bind_ret = bind((int)socket_, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
    if (bind_ret == -1) {
        error->SetErrorValue(ERROR_DEFINE::SOCKET_BIND_FAILED, strerror(errno));
        return;
    }

    int listen_ret = listen((int)socket_, 5);
    if (listen_ret == -1) {
        error->SetErrorValue(ERROR_DEFINE::SOCKET_LISTEN_FAILED, strerror(errno));
        return ;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}

TRTcpSocket TRTcpAcceptor::AcceptClient(TRError* error) {
    TRTcpSocket return_socket;

    struct sockaddr_in client_addr;
    memset(&client_addr, 0x00, sizeof(client_addr));

    socklen_t client_addr_size = sizeof(client_addr_size);
    int client_socket = accept((int)socket_, (struct sockaddr*)&client_addr, &client_addr_size);
    if (client_socket == -1) {
        error->SetErrorValue(ERROR_DEFINE::CLIENT_ACCEPT_FAILED, strerror(errno));
        return return_socket;
    }

    return_socket.SetRawSocketDescriptor(client_socket);
    error->SetErrorCode(ERROR_DEFINE::SUCCESS);

    return return_socket;
}

#endif
