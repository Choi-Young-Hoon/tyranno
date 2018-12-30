#ifndef __TYRANNO_CODEC_ID_HEADER__
#define __TYRANNO_CODEC_ID_HEADER__

#include "TR_VIDEO_TYPE.hpp"

class TRCodecID {
public: 
    explicit TRCodecID();
    explicit TRCodecID(TR_CODEC_ID video_codec_id, TR_CODEC_ID audio_codec_id);
    virtual ~TRCodecID();

public:
    // set
    void SetVideoCodecID(TR_CODEC_ID video_codec_id);
    void SetAudioCodecID(TR_CODEC_ID audio_codec_id);

    // get
    TR_CODEC_ID GetVideoCodecID();
    TR_CODEC_ID GetAudioCodecID();

private:
    TR_CODEC_ID video_codec_id_;
    TR_CODEC_ID audio_codec_id_;
};

#endif