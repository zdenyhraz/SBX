cmake_minimum_required(VERSION 3.0.0)

#set(CMAKE_TOOLCHAIN_FILE "E:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 17)

set(SRCS_DIR "E:/SBX_VSCode/src/")
set(OPENCV_INCLUDE_DIR "C:/include/opencv/build/include/")
set(SPDLOG_INCLUDE_DIR "C:/include/spdlog/include/")
set(OPENCV_LIBRARY_DIR "C:/include/opencv/build/x64/vc14/lib/")

project(SBX VERSION 1.0.0)

#find_package(OpenCV REQUIRED)
#find_package(spdlog REQUIRED)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.h)
add_executable(SBX ${sources})

target_include_directories(SBX PUBLIC ${SRCS_DIR})
target_include_directories(SBX PUBLIC ${OPENCV_INCLUDE_DIR})
target_include_directories(SBX PUBLIC ${SPDLOG_INCLUDE_DIR})
target_link_libraries(SBX ${OPENCV_LIBRARY_DIR})
