#ifndef __TYRANNO_STREAM_INDEX_HEADER__
#define __TYRANNO_STREAM_INDEX_HEADER__

class TRStreamIndex {
public:
    explicit TRStreamIndex();
    explicit TRStreamIndex(int video_stream_index, int audio_stream_index);
    virtual ~TRStreamIndex();

public:
    // set
    void SetVideoStreamIndex(int video_stream_index);
    void SetAudioStreamIndex(int audio_stream_index);

    // get
    int GetVideoStreamIndex();
    int GetAudioStreamIndex();

private:
    int video_stream_index_;
    int audio_stream_index_;
};

#endif