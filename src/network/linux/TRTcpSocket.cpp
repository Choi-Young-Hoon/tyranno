#ifdef __linux__

#include "TRTcpSocket.hpp"

#include <cstdio>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


TRTcpSocket::TRTcpSocket() 
: socket_descriptor_(0)
{}

TRTcpSocket::TRTcpSocket(int socket)
: socket_descriptor_(socket)
{}

TRTcpSocket::~TRTcpSocket() 
{}


void TRTcpSocket::CreateSocket(TRError* error) {
    this->socket_descriptor_ = socket(PF_INET, SOCK_STREAM, 0);
    if (this->socket_descriptor_ == -1) {
        error->SetErrorValue(ERROR_DEFINE::SOCKET_CREATE_FAILED, strerror(errno));
        return;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
}

void TRTcpSocket::CloseSocket() {
    if (socket_descriptor_ != 0) {
        close(socket_descriptor_);
    }

    socket_descriptor_ = 0;
}

void TRTcpSocket::SetEndPoint(TRTcpEndPoint& end_point) {
    this->end_point_ = end_point;
}

void TRTcpSocket::SetRawSocketDescriptor(int socket_descriptor) {
    this->socket_descriptor_ = socket_descriptor;
}

bool TRTcpSocket::IsCreated() {
    if (socket_descriptor_ == 0) {
        return false;
    } 

    return true;
}

int TRTcpSocket::Send(unsigned char* data, int length, TRError* error) {
    TRByteBuffer buffer(data, length);

    return Send(buffer, error);
}

int TRTcpSocket::Send(const char* data, TRError* error) {
    TRByteBuffer buffer(data);

    return Send(buffer, error);
}

int TRTcpSocket::Send(TRByteBuffer& buffer, TRError* error) {
    int send_size = send(this->socket_descriptor_, buffer.GetData(), buffer.GetLength(), 0);
    if (send_size == -1) {
        error->SetErrorValue(ERROR_DEFINE::DATA_SEND_FAILED, strerror(errno)); 
        return -1;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
    return send_size;
}

int TRTcpSocket::Recv(unsigned char* data, int data_buffer_size, TRError* error) {
    int recv_size = recv(this->socket_descriptor_, (void*)data, (size_t)data_buffer_size, 0);
    if(recv_size == -1) {
        error->SetErrorValue(ERROR_DEFINE::DATA_RECV_FAILED, strerror(errno));
        return -1;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
    return recv_size;
}

int TRTcpSocket::Recv(TRByteBuffer* buffer, TRError* error) {
    unsigned char data[DEFAULT_RECV_BUFFER_SIZE] = {0, };
    
    int recv_size = Recv(data, DEFAULT_RECV_BUFFER_SIZE, error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        return -1;
    } 

    buffer->SetData(data, recv_size);
    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
    return recv_size;
}

TRTcpSocket::operator int() {
    return this->socket_descriptor_;
}

#endif
