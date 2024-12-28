include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(adas STATIC ${SOURCES})