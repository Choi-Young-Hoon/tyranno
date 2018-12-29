# tyranno library
set (TYRANNO_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include)
set (TYRANNO_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/lib)

# googletest library
set (GTEST_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/thirdparty/googletest/googletest/include)
set (GTEST_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/thirdparty/googletest/build/lib)

# CPP Version
get_property(CPP_VERSION GLOBAL PROPERTY GLOBAL_CPP_VERSION)
set (CMAKE_CXX_STANDARD ${CPP_VERSION})

# compile option
add_compile_options (-W -Wall)

# Debug compile option
set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")

# Release compile option
set (CMAKE_CXX_FLAGS_RELEASE "-O3")

set (OUTPUT test.out)
set (SOURCE main.cpp
            TRByteBuffer_TEST.cpp
            TRProtocolBody_TEST.cpp
            TRProtocolHeader_TEST.cpp)

include_directories (${GTEST_INCLUDE_PATH} ${TYRANNO_INCLUDE_PATH})
link_directories    (${GTEST_LIBRARY_PATH} ${TYRANNO_LIBRARY_PATH})

find_library (GTESTLIB NAMES libgtest.a HINTS ${GTEST_LIBRARY_PATH} REQUIRED)

add_executable (${OUTPUT} ${SOURCE})
target_link_libraries (${OUTPUT} -pthread ${GTESTLIB} tyrannoutil tyrannoprotocol)

