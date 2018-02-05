cmake_minimum_required(VERSION 3.0)

project(SimpleExample)

find_package(PkgConfig REQUIRED)

#set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/pkgconfig;/usr/share/pkgconfig")

pkg_check_modules(GTKMM gtkmm-3.0)
#GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES are set

#add_subdirectory(.)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

message("include:  ${GTKMM_INCLUDE_DIRS}")

add_executable(SimpleExample SimpleExample.cpp)

target_link_libraries(SimpleExample ${GTKMM_LIBRARIES})
