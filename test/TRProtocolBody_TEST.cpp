#include "gtest/gtest.h"

#include "protocol/TRProtocolBodyInterface.hpp"
#include "protocol/TRProtocolExitRequest.hpp"
#include "protocol/TRProtocolExitResponse.hpp"
#include "protocol/TRProtocolRegistRequest.hpp"
#include "protocol/TRProtocolRegistResponse.hpp"
#include "protocol/TRProtocolTranscodingRequest.hpp"
#include "protocol/TRProtocolTranscodingResponse.hpp"
#include "protocol/TRProtocolMuxingRequest.hpp"
#include "protocol/TRProtocolMuxingResponse.hpp"

TEST(TRProtocolExitReuqest_TEST, marshal_unmarshal) {
    TRProtocolExitRequest exit_request_marshal;

    TRByteBuffer byte_buffer;
    exit_request_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolExitRequest exit_request_unmarshal;
    exit_request_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);
}

TEST(TRProtocolExitResponse_TEST, marshal_unmarshal) {
    TRProtocolExitResponse exit_response_marshal;

    TRByteBuffer byte_buffer;
    exit_response_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolExitResponse exit_response_unmarshal;
    exit_response_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);
}

TEST(TRProtocolRegistRequest_TEST, marshal_unmarshal) {
    TRProtocolRegistRequest regist_request_marshal;

    int system_version = 122;
    regist_request_marshal.SetSystemVersion(system_version);

    TRByteBuffer byte_buffer;
    regist_request_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolRegistRequest regist_request_unmarshal;
    regist_request_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    ASSERT_EQ(regist_request_unmarshal.GetSystemVersion(), system_version);
}

TEST(TRProtocolRegistRequest_TEST, marshal_unmarshal_FAILED) {
    TRProtocolRegistRequest regist_request_marshal;

    int system_version = 122;
    regist_request_marshal.SetSystemVersion(system_version);

    TRByteBuffer byte_buffer;
    regist_request_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolRegistRequest regist_request_unmarshal;
    regist_request_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    ASSERT_TRUE(regist_request_unmarshal.GetSystemVersion() != (system_version - 100));
}

TEST(TRProtocolRegistResponse_TEST, marshal_unmarshal) {
    TRProtocolRegistResponse regist_response_marshal;

    int session = 234;
    
    TRByteBuffer byte_buffer;
    regist_response_marshal.SetSession(session);
    regist_response_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolRegistResponse regist_response_unmarshal;
    regist_response_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    ASSERT_EQ(regist_response_unmarshal.GetSession(), session);
}

TEST(TRProtocolRegistResponse_TEST, marshal_unmarshal_FAILED) {
    TRProtocolRegistResponse regist_response_marshal;

    int session = 234;
    
    TRByteBuffer byte_buffer;
    regist_response_marshal.SetSession(session);
    regist_response_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolRegistResponse regist_response_unmarshal;
    regist_response_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), ERROR_DEFINE::SUCCESS);

    ASSERT_TRUE(regist_response_unmarshal.GetSession() != (session - 100));
}