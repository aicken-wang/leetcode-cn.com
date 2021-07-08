cmake_minimum_required(VERSION 2.8)
project(test)
# 设置编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14 -DOS_LNX -Wwrite-strings -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMATCH_MOCKUP")
# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 加载子目录
add_subdirectory(./reorder_odd_even)
add_subdirectory(./list)
add_subdirectory(./duplicate)
add_subdirectory(./numberof)
add_subdirectory(./replace_blank)