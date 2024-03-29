cmake_minimum_required(VERSION 3.12)

enable_testing()
find_package(GTest REQUIRED)

# -fsanitize=address 地址消毒
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0 -fsanitize=address -ftest-coverage -fprofile-arcs")

# 存放 leetcode 源文件
# dynamic lib
add_library(leetcode SHARED
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_unknown_1.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_307.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_310.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_373.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_380.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_396.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_728.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_787.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_930.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_954.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_1094.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_1606.cpp
    ${PROJECT_SOURCE_DIR}/src/lc_src/lc_1705.cpp
)

# lib include
target_include_directories(leetcode
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/lc_header
)

# 测试程序 exe
add_executable(run_test
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# 测试程序依赖
target_link_libraries(run_test
    PRIVATE
    leetcode
    GTest::GTest
    GTest::Main
)

# exe include
target_include_directories(run_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
)

# 可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/bin)
# 库输出路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/lib)
