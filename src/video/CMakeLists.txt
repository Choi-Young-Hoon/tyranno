# tyranno
set (TYRANNO_UTIL_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include/video)
set (FFMPEG_INCLUDE_PATH  ${TYRANNO_SOURCE_DIR}/thirdparty/FFmpeg/build/include)
set (FFMPEG_LIBRARY_PATH  ${TYRANNO_SOURCE_DIR}/thirdparty/FFmpeg/build/lib)
set (TYRANNO_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include)
set (TYRANNO_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/lib)

link_directories(${FFMPEG_LIBRARY_PATH})
include_directories(${FFMPEG_INCLUDE_PATH} ${TYRANNO_UTIL_INCLUDE_PATH} ${TYRANNO_INCLUDE_PATH})

# CPP Version
get_property (CPP_VERSION GLOBAL PROPERTY GLOBAL_CPP_VERSION)
set (CMAKE_CXX_STANDARD ${CPP_VERSION})

set (LIBVIDEO tyrannovideo)
set (LIBVIDEONAME lib${LIBVIDEO}.a)
set (SOURCES TRVideo.cpp
             TRRawFrame.cpp
             TRFrame.cpp 
             TRCodec.cpp 
             TRCodecID.cpp
             TRCodecManager.cpp
             TRDecodeCodec.cpp 
             TREncodeCodec.cpp 
             TRDecoder.cpp
             TREncoder.cpp
             )

# compile option
add_compile_options (-W -Wall)

# Debug compile option
set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")

# Release compile option
set (CMAKE_CXX_FLAGS_RELEASE "-O3")

add_library(${LIBVIDEO} ${SOURCES})

install (FILES ${LIBVIDEONAME} DESTINATION ${TYRANNO_LIBRARY_PATH})