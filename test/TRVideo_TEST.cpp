#include "gtest/gtest.h"

#include "video/TRVideo.hpp"
#include "video/TRDecoder.hpp"
#include "video/TRCodecManager.hpp"

#include <iostream>
#include "TEST_DEFINE.hpp"

static bool openVideo(TRVideo* video);

TEST(TRVideoDecode_TEST, TRDecoderCodec_TEST) {
    TRVideo video;
    ASSERT_TRUE(openVideo(&video));

    TRError error;
    TRCodec* decode_codec = TRCodecManager::CreateCodec(TRCodecManager::DECODE_CODEC, video, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    video.Close();
    delete decode_codec;
}

TEST(TRVideoDecode_TEST, TRDecoder_TEST) {
    TRVideo video;
    ASSERT_TRUE(openVideo(&video));

    TRError error;
    TRDecoder decoder;
    decoder.SetCodec(TRCodecManager::CreateCodec(TRCodecManager::DECODE_CODEC, video, &error));
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    video.Close();
}


static bool openVideo(TRVideo* video) {
    TRError error;

    video->Open(TEST_VIDEO_FILE, &error);
    if (error.GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        std::cout << error.GetErrorMessage() << std::endl;
        return false;
    }

    std::cout << "Video codec ID: " << video->GetVideoCodecID() << std::endl;
    std::cout << "Audio codec ID: " << video->GetAudioCodecID() << std::endl;
    
    std::cout << "Video stream count: " << video->GetStreamsCount() << std::endl;
    return true;
}