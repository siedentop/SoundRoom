
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/../ )
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(SoundRoomTest_SRCS SoundRoomTest.cpp)
qt4_automoc(${SoundRoomTest_SRCS})
add_executable(SoundRoomTest ${SoundRoomTest_SRCS})
add_test(SoundRoomTest SoundRoomTest)
target_link_libraries(SoundRoomTest SoundRoomlib ${QT_QTTEST_LIBRARY})
