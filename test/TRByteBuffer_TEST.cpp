#include "gtest/gtest.h"

#include "util/TRByteBuffer.hpp"

static unsigned char g_temp_data[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
static unsigned int  g_temp_data_length = 10;


TEST (TRByteBuffer_TEST, Constructor) {
    TRByteBuffer byteBuffer(g_temp_data, g_temp_data_length);

    ASSERT_EQ(byteBuffer.GetLength(), g_temp_data_length);

    for (int i = 0; i < g_temp_data_length; i++) {
        ASSERT_EQ(byteBuffer[i], g_temp_data[i]);
    }
}

TEST (TRByteBuffer_TEST, Empty) {
    TRByteBuffer byteBuffer(g_temp_data, g_temp_data_length);
    
    ASSERT_TRUE(!byteBuffer.IsEmpty());
    byteBuffer.Clear();
    ASSERT_TRUE(byteBuffer.IsEmpty());
}

TEST (TRByteBuffer_TEST, SetData) {
    TRByteBuffer byteBuffer;

    byteBuffer.SetData(g_temp_data, g_temp_data_length);
    ASSERT_EQ(byteBuffer.GetLength(), g_temp_data_length);

    for (int i = 0; i < g_temp_data_length; i++) {
        ASSERT_EQ(byteBuffer[i], g_temp_data[i]);
    }
}

TEST (TRByteBuffer_TEST, SetData_2) {
    TRByteBuffer byteBuffer(g_temp_data, g_temp_data_length);

    ASSERT_TRUE(!byteBuffer.IsEmpty());

    byteBuffer.Clear();
    ASSERT_TRUE(byteBuffer.IsEmpty());

    byteBuffer.SetData(g_temp_data, g_temp_data_length);
    ASSERT_EQ(byteBuffer.GetLength(), g_temp_data_length);
}

TEST(TRByteBuffer_TEST, Append) {
    TRByteBuffer byteBuffer;

    byteBuffer.Append(g_temp_data, g_temp_data_length);
    ASSERT_EQ(byteBuffer.GetLength(), g_temp_data_length);

    byteBuffer.Append(g_temp_data, g_temp_data_length);
    ASSERT_EQ(byteBuffer.GetLength(), g_temp_data_length * 2);
}

TEST(TRByteBuffer_TEST, Const_char) {
    const char* temp_data = "hello world";
    int   temp_data_length = strlen(temp_data);

    TRByteBuffer byteBuffer(temp_data);
    ASSERT_EQ(byteBuffer.GetLength(), temp_data_length + 1);

    char* ret_data = (char*)byteBuffer.GetData();
    ASSERT_TRUE(strcmp(ret_data, temp_data) == 0);
}

TEST(TRByteBuffer_TEST, Sub) {
    TRByteBuffer byteBuffer(g_temp_data, g_temp_data_length);

    int start_index = 1;
    int end_index   = 3;

    TRByteBuffer subBuffer = byteBuffer.Sub(start_index, end_index);
    for (int i = start_index; i < end_index; i++) {
        ASSERT_EQ(g_temp_data[i], subBuffer[i - start_index]);
    }
}