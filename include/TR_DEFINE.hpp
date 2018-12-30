#ifndef __TR_DEFINE_HEADER__
#define __TR_DEFINE_HEADER__

#define TR_UNUSED(var) (void)var;


#define TR_ERROR_DEFINE 
enum _ERROR_DEFINE {    
    SUCCESS = 0,

    MEMORY_ALLOC_FAILED,


///////////////////////// protocol
    PROTOCOL_ERROR_START,
    UNMARSHAL_DATA_SIZE_NOT_ENOUGH,
    PROTOCOL_ERROR_END,
/////////////////////////


///////////////////////// network
    NETWORK_ERROR_START,
    SOCKET_CREATE_FAILED,
    PORT_INFO_EMPTY,
    SOCKET_BIND_FAILED,
    SOCKET_LISTEN_FAILED,
    DATA_SEND_FAILED,
    DATA_RECV_FAILED,
    SERVER_CONNECT_FAILED,
    CLIENT_ACCEPT_FAILED,
    NETWORK_ERROR_END,
/////////////////////////


///////////////////////// video
    VIDEO_ERROR_START,
    FILE_OPEN_FAILED,
    FILE_NOT_OPENED,
    STREAM_INFO_NOT_FOUND,
    READ_FRAME_FAILED,
    NOT_FOUND_VIDEO_CODEC,
    NOT_FOUND_AUDIO_CODEC,
    UNKNOWN_CODEC_TYPE,
    VIDEO_ERROR_END,
/////////////////////////
};                      
typedef enum _ERROR_DEFINE ERROR_DEFINE; 

#endif