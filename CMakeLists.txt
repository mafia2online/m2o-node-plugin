cmake_minimum_required(VERSION 2.8)
project(m2o-node)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

if (WIN32)
    set(NODE_DLL node.dll)

    if (WIN64)
        set(SYS_PATH win64)
    else()
        set(SYS_PATH win32)
    endif()
elseif(APPLE)
    set(NODE_DLL libnode.59.dylib)
    set(SYS_PATH mac)
else()
    set(NODE_DLL libnode.so.59)
    set(SYS_PATH lin)
endif()

include_directories(include include/node include/v8 include/uv)
link_directories(${CMAKE_SOURCE_DIR}/lib/${SYS_PATH})

add_definitions(-DBUILDING_NODE_EXTENSION=1 -DEXTERNAL_NAPI=1)

if (TEST)
    add_definitions(-DTEST=1)
    add_executable(m2o_node src/main.cpp src/node.cpp)
else()
    add_library(m2o_node SHARED src/main.cpp src/node.cpp)
endif()

if (WIN32)
    set(LIBRARIES v8_libbase v8_libplatform node shlwapi dbghelp winmm)
else()
    set(LIBRARIES v8_libbase v8_libplatform node pthread dl m)

    add_custom_command(TARGET m2o_node PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_SOURCE_DIR}/lib/${SYS_PATH}/${NODE_DLL}" "${CMAKE_SOURCE_DIR}/lib/${SYS_PATH}/libnode.so"
    )
endif()

target_link_libraries(m2o_node ${LIBRARIES})

add_custom_command(TARGET m2o_node POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/misc/index.js" "${CMAKE_CURRENT_BINARY_DIR}/"
)

add_custom_command(TARGET m2o_node POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/lib/${SYS_PATH}/${NODE_DLL}" "${CMAKE_CURRENT_BINARY_DIR}/"
)
