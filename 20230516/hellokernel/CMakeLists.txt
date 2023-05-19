cmake_minimum_required(VERSION 3.1)

project(HelloKernel LANGUAGES CXX)

find_package(OpenCL REQUIRED)

add_executable(${PROJECT_NAME} hellokernel.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenCL::OpenCL)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20
                                                 CXX_STANDARD_REQUIRED ON
                                                 CXX_EXTENSIONS OFF)

target_compile_definitions(${PROJECT_NAME} PRIVATE CL_TARGET_OPENCL_VERSION=300)