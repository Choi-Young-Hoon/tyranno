# tyranno library
set (TYRANNO_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include)
set (TYRANNO_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/lib)

# googletest library
set (GTEST_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/thirdparty/googletest/googletest/include)
set (GTEST_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/thirdparty/googletest/build/lib)

# ffmpeg library
set (FFMPEG_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/thirdparty/FFmpeg/build/include)
set (FFMPEG_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/thirdparty/FFmpeg/build/lib)

# CPP Version
get_property(CPP_VERSION GLOBAL PROPERTY GLOBAL_CPP_VERSION)
set (CMAKE_CXX_STANDARD ${CPP_VERSION})

# Debug compile option
set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")

# Release compile option
set (CMAKE_CXX_FLAGS_RELEASE "-O3")

set (OUTPUT test.out)
set (SOURCE main.cpp
            TRByteBuffer_TEST.cpp
            TRProtocolBody_TEST.cpp
            TRProtocolHeader_TEST.cpp  
            TRVideoDecode_TEST.cpp)

include_directories (${GTEST_INCLUDE_PATH} ${FFMPEG_INCLUDE_PATH} ${TYRANNO_INCLUDE_PATH})
link_directories    (${GTEST_LIBRARY_PATH} ${FFMPEG_LIBRARY_PATH} ${TYRANNO_LIBRARY_PATH})

find_library (GTESTLIB NAMES libgtest.a HINTS ${GTEST_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_FORMAT_LIB NAMES libavformat.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_CODEC_LIB NAMES libavcodec.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_SWSCALE_LIB NAMES libswscale.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_UTIL_LIB NAMES libavutil.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_FILTER_LIB NAMES libavfilter.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_POST_PROC_LIB NAMES libpostproc.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)
find_library (FFMPEG_SWRESAMPLE_LIB NAMES libswresample.a HINTS ${FFMPEG_LIBRARY_PATH} REQUIRED)

set (FFMPEG_LIB_LIST ${FFMPEG_FORMAT_LIB} 
                     ${FFMPEG_CODEC_LIB} 
                     ${FFMPEG_SWSCALE_LIB} 
                     ${FFMPEG_UTIL_LIB} 
                     ${FFMPEG_FILTER_LIB}
                     ${FFMPEG_POST_PROC_LIB}
                     ${FFMPEG_SWRESAMPLE_LIB})
set (TYRANNO_LIB_LIST tyrannoutil tyrannoprotocol tyrannovideo)
set (OTHER_LIB_LIST -pthread -lz)

add_executable (${OUTPUT} ${SOURCE})
target_link_libraries (${OUTPUT} ${GTESTLIB} ${TYRANNO_LIB_LIST} ${FFMPEG_LIB_LIST} ${OTHER_LIB_LIST})

