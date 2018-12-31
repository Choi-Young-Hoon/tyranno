#ifndef __TYRANNO_CODEC_MANAGER_HEADER__
#define __TYRANNO_CODEC_MANAGER_HEADER__

#include "TRCodec.hpp"
#include "TRCodecID.hpp"
#include "TRCodecParameters.hpp"
#include "TRDecodeCodec.hpp"
#include "TREncodeCodec.hpp"

class TRCodecManager {
public:
    enum _CODEC_TYPE {
        DECODE_CODEC = 0,
        ENCODE_CODEC,
    };
    typedef enum _CODEC_TYPE CODEC_TYPE;

public:
    static TRCodec* CreateCodec(CODEC_TYPE codec_type, TRCodecID& codec_id, TRCodecParameters& codec_parameters , TRError* error);
    static TRCodec* CreateCodec(CODEC_TYPE codec_type, TRVideoReader& video, TRError* error);

private:
    static TRCodec* CreateCodec(CODEC_TYPE codec_type, TRError* error);

    static TRCodec* CreateEncodeCodec(TRError* error);
    static TRCodec* CreateDecodeCodec(TRError* error);

private:
    explicit TRCodecManager();
    virtual ~TRCodecManager();
};

#endif