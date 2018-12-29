#ifndef __TYRANNO_TCP_ENDPOINT_HEADER__
#define __TYRANNO_TCP_ENDPOINT_HEADER__

#include <string>

class TRTcpEndPoint {
public:
    enum _IP_PROTOCOL_VERSION {
        IP_V4 = 0,
        IP_V6,
    };
    typedef enum _IP_PROTOCOL_VERSION IP_PROTOCOL_VERSION;

public:
    explicit TRTcpEndPoint();
    explicit TRTcpEndPoint(int port, IP_PROTOCOL_VERSION ip_protocol_version = IP_V4);
    virtual ~TRTcpEndPoint();

public:
    void SetIpAddress(const char* ip_address);
    void SetIpAddress(std::string& ip_address);
    void SetPort(int port);
    void SetProtocolVersion(IP_PROTOCOL_VERSION protocol_version);

    std::string GetIpAddress();
    int GetPort();
    IP_PROTOCOL_VERSION GetProtocolVersion();

private:
    std::string ip_address_;
    int port_;

    IP_PROTOCOL_VERSION ip_protocol_version_;
};

#endif