#ifndef __TYRANNO_SOCKET_HEADER__
#define __TYRANNO_SOCKET_HEADER__

#include "TRError.hpp"
#include "TRTcpEndPoint.hpp"
#include "util/TRByteBuffer.hpp"

#define DEFAULT_RECV_BUFFER_SIZE 2048

class TRTcpSocket {
public:
    explicit TRTcpSocket();
    explicit TRTcpSocket(int socket);
    virtual ~TRTcpSocket();

public:
    void CreateSocket(TRError* error);
    void CloseSocket();

    void SetEndPoint(TRTcpEndPoint& end_point);
    void SetRawSocketDescriptor(int socket_descriptor);

    bool IsCreated();

    int Send(unsigned char* data, int length, TRError* error);
    int Send(const char* data, TRError* error);
    int Send(TRByteBuffer& buffer, TRError* error);

    int Recv(unsigned char* data, int data_buffer_size, TRError* error);
    int Recv(TRByteBuffer* buffer, TRError* error);

public:
    operator int();

private:
    int socket_descriptor_;

    TRTcpEndPoint end_point_;
};

#endif
