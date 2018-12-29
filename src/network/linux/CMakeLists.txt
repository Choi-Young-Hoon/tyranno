# tyranno
set (TYRANNO_UTIL_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include/network)
set (TYRANNO_INCLUDE_PATH ${TYRANNO_SOURCE_DIR}/include)
set (TYRANNO_LIBRARY_PATH ${TYRANNO_BINARY_DIR}/lib)

include_directories(${TYRANNO_UTIL_INCLUDE_PATH} ${TYRANNO_INCLUDE_PATH})

# CPP Version
get_property (CPP_VERSION GLOBAL PROPERTY GLOBAL_CPP_VERSION)
set (CMAKE_CXX_STANDARD ${CPP_VERSION})

set (LIBNETWORK tyrannonetwork)
set (LIBNETWORKNAME lib${LIBNETWORK}.a)
set (SOURCES TRTcpAcceptor.cpp 
             TRTcpConnector.cpp
             TRTcpAcceptor.cpp)

# compile option
add_compile_options (-W -Wall)

# Debug compile option
set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")

# Release compile option
set (CMAKE_CXX_FLAGS_RELEASE "-O3")

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TYRANNO_LIBRARY_PATH})

add_library(${LIBNETWORK} ${SOURCES})

install (FILES ${LIBNETWORKNAME} DESTINATION ${TYRANNO_LIBRARY_PATH})