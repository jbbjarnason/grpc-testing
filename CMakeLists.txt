cmake_minimum_required(VERSION 3.16)
project(gRPC_test)

# Insert custom cmake files into scope
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

# Declare system dependencies
# TODO: provide FindAsio.cmake
# find_package(Asio 1.0 REQUIRED)

add_executable(GRPC_SERVER
    src/main.cpp
    src/Server.cpp
)

target_compile_features(GRPC_SERVER
    PRIVATE
        cxx_std_20
)

target_include_directories(GRPC_SERVER
    PUBLIC
        $<INSTALL_INTERFACE:include/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc/public>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(GRPC_SERVER
    PRIVATE
        pthread
)

