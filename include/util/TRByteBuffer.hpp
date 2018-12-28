#ifndef __TYRANNO_BYTE_BUFFER_HEADER__
#define __TYRANNO_BYTE_BUFFER_HEADER__

#include <vector>

class TRByteBuffer {
public:
    explicit TRByteBuffer();
    explicit TRByteBuffer(unsigned char* data, int length);
    explicit TRByteBuffer(const char* data);

    virtual ~TRByteBuffer();


public:
    const unsigned char* GetData();
    int                  GetLength();
    
    void SetData(unsigned char* data, int length);
    void SetData(const char* data);
    
    TRByteBuffer& Append(TRByteBuffer& buffer);
    TRByteBuffer& Append(unsigned char* data, int length);

    TRByteBuffer Sub(int start_index, int end_index);


public:
    unsigned char operator[](int index); 
    TRByteBuffer& operator+=(TRByteBuffer& buffer);
    TRByteBuffer& operator+ (TRByteBuffer& buffer);


private:
    std::vector<unsigned char> buffer_;
};

#endif
