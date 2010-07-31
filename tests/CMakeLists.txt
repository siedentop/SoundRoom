include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/../ )
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

set(ViewTest_SRCS ViewTest.cpp)
qt4_automoc(${ViewTest_SRCS})
add_executable(ViewTest ${ViewTest_SRCS})
add_test(ViewTest ViewTest)
target_link_libraries(ViewTest SoundRoomlib ${QT_QTTEST_LIBRARY})

set(ComplexTest_SRCS ComplexTest.cpp)
qt4_automoc(${ComplexTest_SRCS})
add_executable(ComplexTest ${ComplexTest_SRCS})
add_test(ComplexTest ComplexTest)
target_link_libraries(ComplexTest SoundRoomlib ${QT_QTTEST_LIBRARY}) # TODO: This absolute bs. Who needs SoundRoomlib?

set(SoundRoomTest_SRCS SoundRoomTest.cpp)
qt4_automoc(${SoundRoomTest_SRCS})
add_executable(SoundRoomTest ${SoundRoomTest_SRCS})
add_test(SoundRoomTest SoundRoomTest)
target_link_libraries(SoundRoomTest SoundRoomlib ${QT_QTTEST_LIBRARY})
