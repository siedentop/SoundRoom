project(SoundRoom)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)	
include(${QT_USE_FILE})
enable_testing()

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(SoundRoom_SRCS SoundRoom.cpp main.cpp)

add_library(SoundRoomlib SHARED SoundRoom.cpp)
target_link_libraries(SoundRoomlib ${QT_QTCORE_LIBRARY} ${QT_LIBRARIES})

qt4_automoc(${SoundRoom_SRCS})
add_executable(SoundRoom ${SoundRoom_SRCS})
target_link_libraries(SoundRoom ${QT_QTCORE_LIBRARY} ${QT_LIBRARIES})

add_subdirectory(tests)
