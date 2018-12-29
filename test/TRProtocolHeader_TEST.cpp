#include "gtest/gtest.h"

#include "protocol/TRProtocolHeaderInterface.hpp"
#include "protocol/TRProtocolRequestHeader.hpp"
#include "protocol/TRProtocolResponseHeader.hpp"

TEST(TRProtocolRequestHeader_TEST, marshal_unmarshal_TEST) {
    uint request_type = 600;
    uint8_t system_type = 1;
    uint16_t version = 3;
    uint session = 100;

    TRProtocolRequestHeader request_header_marshal;
    request_header_marshal.SetRequestType(request_type);
    request_header_marshal.SetSystemType(system_type);
    request_header_marshal.SetVersion(version);
    request_header_marshal.SetSession(session);

    TRByteBuffer byte_buffer;
    request_header_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolRequestHeader request_header_unmarshal;
    request_header_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), TRProtocolRequestHeader::SUCCESS);

    ASSERT_EQ(request_header_unmarshal.GetRequestType(), request_type);
    ASSERT_EQ(request_header_unmarshal.GetSystemType(), system_type);
    ASSERT_EQ(request_header_unmarshal.GetVersion(), version);
    ASSERT_EQ(request_header_unmarshal.GetSession(), session);     
}

TEST(TRProtocolResponseHeader_TEST, mrashal_unmarshal_TEST) {
    TRProtocolResponseHeader response_header_marshal;

    int request_type = 122;
    int result_code = 255;
    std::string error_message = "ERROR !!!";

    TRByteBuffer byte_buffer; 
    response_header_marshal.SetRequestType(request_type);
    response_header_marshal.SetResultCode(result_code);
    response_header_marshal.SetErrorMessage(error_message);
    response_header_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolResponseHeader response_header_unmarshal;
    response_header_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), TRProtocolResponseHeader::SUCCESS);

    ASSERT_EQ(response_header_unmarshal.GetRequestType(), request_type);
    ASSERT_EQ(response_header_unmarshal.GetResultCode(), result_code);
    ASSERT_EQ(response_header_unmarshal.GetErrorMessage(), error_message);
}

TEST(TRProtocolRequestHeader_TEST, marshal_unmarshal_FAILED_TEST) {
    uint request_type = 600;
    uint8_t system_type = 1;
    uint16_t version = 3;
    uint session = 100;

    TRProtocolRequestHeader request_header_marshal;
    request_header_marshal.SetRequestType(request_type);
    request_header_marshal.SetSystemType(system_type);
    request_header_marshal.SetVersion(version);
    request_header_marshal.SetSession(session);

    TRByteBuffer byte_buffer;
    request_header_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolRequestHeader request_header_unmarshal;
    request_header_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), TRProtocolRequestHeader::SUCCESS);

    ASSERT_TRUE(request_header_unmarshal.GetRequestType() != request_type - 1);
    ASSERT_TRUE(request_header_unmarshal.GetSystemType() != system_type - 1);
    ASSERT_TRUE(request_header_unmarshal.GetVersion() != version - 1);
    ASSERT_TRUE(request_header_unmarshal.GetSession() != session - 1);     
}

TEST(TRProtocolResponseHeader_TEST, mrashal_unmarshal_FAILED_TEST) {
    TRProtocolResponseHeader response_header_marshal;

    int request_type = 211;
    int result_code = 255;
    std::string error_message = "ERROR !!!";

    TRByteBuffer byte_buffer; 
    response_header_marshal.SetRequestType(request_type);
    response_header_marshal.SetResultCode(result_code);
    response_header_marshal.SetErrorMessage(error_message);
    response_header_marshal.marshal(&byte_buffer);

    TRError error;
    TRProtocolResponseHeader response_header_unmarshal;
    response_header_unmarshal.unmarshal(byte_buffer, &error);
    ASSERT_EQ(error.GetErrorCode(), TRProtocolResponseHeader::SUCCESS);

    ASSERT_TRUE(response_header_unmarshal.GetRequestType() != (request_type - 10));
    ASSERT_TRUE(response_header_unmarshal.GetResultCode() != (result_code + 100));
    ASSERT_TRUE(response_header_unmarshal.GetErrorMessage() != (error_message + "HELLO"));
}