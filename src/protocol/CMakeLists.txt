# tyranno
set (TYRANNO_UTIL_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include/protocol)
set (TYRANNO_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include)
set (TYRANNO_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/lib)

include_directories(${TYRANNO_UTIL_INCLUDE_PATH} ${TYRANNO_INCLUDE_PATH})

# CPP Version
get_property (CPP_VERSION GLOBAL PROPERTY GLOBAL_CPP_VERSION)
set (CMAKE_CXX_STANDARD ${CPP_VERSION})

set (LIBPROTOCOL tyrannoprotocol)
set (LIBPROTOCOLNAME lib${LIBPROTOCOL}.a)
set (SOURCES TRProtocolRequestHeader.cpp
             TRProtocolResponseHeader.cpp)

# compile option
add_compile_options (-W -Wall)

# Debug compile option
set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")

# Release compile option
set (CMAKE_CXX_FLAGS_RELEASE "-O3")


add_library(${LIBPROTOCOL} ${SOURCES})

install (FILES ${LIBPROTOCOLNAME} DESTINATION ${TYRANNO_LIBRARY_PATH})