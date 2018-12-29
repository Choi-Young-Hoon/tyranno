#ifndef __TYRANNO_SOCKET_HEADER__
#define __TYRANNO_SOCKET_HEADER__

#include "TRError.hpp"
#include "TRTcpEndPoint.hpp"
#include "util/TRByteBuffer.hpp"

#define DEFAULT_RECV_BUFFER_SIZE 2048

class TRTcpSocket {
public:
    enum _ERROR_DEFINE {
        SUCCESS = 0,
        SOCKET_CREATE_FAILED,

        PORT_INFO_EMPTY,
        SOCKET_BIND_FAILED,
        SOCKET_LISTEN_FAILED,

        DATA_SEND_FAILED,
        DATA_RECV_FAILED,
    };
    typedef enum _ERROR_DEFINE ERROR_DEFINE;


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
