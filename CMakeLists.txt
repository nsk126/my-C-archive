cmake_minimum_required(VERSION 3.0.0)
project(C-Archive VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(
    include/
)

add_library(Matrix
    src/Matrix.cpp
)

add_executable(C-Archive main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
