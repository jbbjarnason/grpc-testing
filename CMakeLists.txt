cmake_minimum_required(VERSION 3.16)
project(gRPC_test)

add_executable(GRPC_SERVER src/main.cpp)

target_include_directories(GRPC_SERVER
    PUBLIC
        $<INSTALL_INTERFACE:include/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc/public>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_features(GRPC_SERVER
    PRIVATE
        cxx_std_20
)
