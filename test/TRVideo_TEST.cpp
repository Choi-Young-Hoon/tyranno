#include "gtest/gtest.h"

#include "video/TRVideo.hpp"
#include "video/TRDecoder.hpp"
#include "video/TRCodecManager.hpp"

#include <iostream>
#include "TEST_DEFINE.hpp"

static bool openVideo(TRVideo* video);


TEST(TRVideo_TEST, TRVideo_Open) {
    TRError error;
    TRVideo video;
    video.Open(TEST_VIDEO_FILE, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    std::cout << "Video codec ID: " << video.GetCodecID().GetVideoCodecID() << std::endl;
    std::cout << "Audio codec ID: " << video.GetCodecID().GetAudioCodecID() << std::endl;
    
    std::cout << "Video stream count: " << video.GetStreamsCount() << std::endl;
}

TEST(TRVideo_TEST, TRVideo_ReadFrame) {
    TRVideo video;
    ASSERT_TRUE(openVideo(&video));

    TRError error; 
    TRFrame frame;
    video.ReadFrame(&frame, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);
}

TEST(TRVideo_TEST, TRDecoderCodec_TEST) {
    TRVideo video;
    ASSERT_TRUE(openVideo(&video));

    TRError error;
    TRCodec* decode_codec = TRCodecManager::CreateCodec(TRCodecManager::DECODE_CODEC, video, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    video.Close();
    delete decode_codec;
}

TEST(TRVideo_TEST, TRDecoder_CreateCodecToVideo_TEST) {
    TRVideo video;
    ASSERT_TRUE(openVideo(&video));

    TRError error;
    TRDecoder decoder;
    decoder.SetCodec(TRCodecManager::CreateCodec(TRCodecManager::DECODE_CODEC, video, &error));
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    TRFrame frame;
    video.ReadFrame(&frame, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    TRRawFrame raw_frame;
    decoder.Decode(frame, &raw_frame, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);
}

TEST(TRVideo_TEST, TRDecoder_CreateCodecToCodecID_TEST) {
    TRVideo video;
    ASSERT_TRUE(openVideo(&video));

    TRCodecID codec_id = video.GetCodecID();
    TRCodecParameters codec_parameters = video.GetCodecParameters();

    TRError error;
    TRDecoder decoder;
    decoder.SetCodec(TRCodecManager::CreateCodec(TRCodecManager::DECODE_CODEC, codec_id, codec_parameters, &error));
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    TRFrame frame;
    video.ReadFrame(&frame, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    TRRawFrame raw_frame;
    decoder.Decode(frame, &raw_frame, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);
}


static bool openVideo(TRVideo* video) {
    TRError error;

    video->Open(TEST_VIDEO_FILE, &error);
    if (error.GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        std::cout << error.GetErrorMessage() << std::endl;
        return false;
    }

    return true;
}