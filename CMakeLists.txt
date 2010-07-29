project(SoundRoom)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)	
include(${QT_USE_FILE})
enable_testing()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_HOME_DIRECTORY}/cmake)
include_directories(${CMAKE_HOME_DIRECTORY} ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

find_package(Eigen2 REQUIRED)
include_directories(${Eigen2_INCLUDE_DIRS})
add_definitions(-DEIGEN_DONT_ALIGN)

set(SoundRoom_SRCS MainWindow.cpp SoundPoint.cpp SoundRoom.cpp speaker.cpp complex.cpp)

add_library(SoundRoomlib SHARED ${SoundRoom_SRCS}) #TODO, HACK this is all not very pretty. the library is not needed
target_link_libraries(SoundRoomlib ${QT_QTCORE_LIBRARY} ${QT_LIBRARIES} 
	${Eigen2_LIBRARIES})

qt4_automoc(${SoundRoom_SRCS})
add_executable(SoundRoom ${SoundRoom_SRCS} main.cpp)
target_link_libraries(SoundRoom ${QT_QTCORE_LIBRARY} ${QT_LIBRARIES}
	${Eigen2_LIBRARIES})

add_subdirectory(tests)
