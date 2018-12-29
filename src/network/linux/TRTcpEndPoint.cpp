#include "TRTcpEndPoint.hpp"


TRTcpEndPoint::TRTcpEndPoint() 
: ip_protocol_version_(IP_PROTOCOL_VERSION::IP_V4)
{}

TRTcpEndPoint::TRTcpEndPoint(int port, IP_PROTOCOL_VERSION ip_protocol_version = IP_V4) 
: port_(port)
, ip_protocol_version_(ip_protocol_version)
{}

TRTcpEndPoint::~TRTcpEndPoint()
{}


void TRTcpEndPoint::SetIpAddress(const char* ip_address) {
    this->ip_address_ = ip_address;
}

void TRTcpEndPoint::SetIpAddress(std::string& ip_address) {
    SetIpAddress(ip_address.c_str());    
}

void TRTcpEndPoint::SetPort(int port) {
    this->port_ = port;
}

void TRTcpEndPoint::SetProtocolVersion(IP_PROTOCOL_VERSION protocol_version) {
    this->ip_protocol_version_ = protocol_version;
}

std::string TRTcpEndPoint::GetIpAddress() {
    return this->ip_address_;
}

int TRTcpEndPoint::GetPort() {
    return this->port_;
}

TRTcpEndPoint::IP_PROTOCOL_VERSION TRTcpEndPoint::GetProtocolVersion() {
    return this->ip_protocol_version_;
}
