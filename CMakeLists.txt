cmake_minimum_required(VERSION 2.8)
project(m2o-node)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

if (WIN32)
    set(NODE_DLL node.dll)
    set(SYS_PATH win)
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
add_executable(m2onode_test src/main.cpp src/node.cpp)
# add_library(m2onode_plugin src/plugin.cpp src/node.cpp)

if (WIN32)
    set(LIBRARIES v8_libbase v8_libplatform node shlwapi dbghelp winmm)
else()
    set(LIBRARIES v8_libbase v8_libplatform node pthread dl m)

    add_custom_command(TARGET m2onode_test PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_SOURCE_DIR}/lib/${SYS_PATH}/${NODE_DLL}" "${CMAKE_SOURCE_DIR}/lib/${SYS_PATH}/libnode.so"
    )
endif()

target_link_libraries(m2onode_test ${LIBRARIES})

add_custom_command(TARGET m2onode_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/misc/script.js" "${CMAKE_CURRENT_BINARY_DIR}/"
)

add_custom_command(TARGET m2onode_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/lib/${SYS_PATH}/${NODE_DLL}" "${CMAKE_CURRENT_BINARY_DIR}/"
)
