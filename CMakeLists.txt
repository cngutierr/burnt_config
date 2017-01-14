cmake_minimum_required(VERSION 3.6)
project(burnt_config)

include(FindPkgConfig)
find_package(PkgConfig)
pkg_check_modules(GLIB glib-2.0 REQUIRED)


set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp BurntConfigTest/basic_check.cpp)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

include_directories(${GLIB_INCLUDE_DIRS})

include_directories(BurntConfig)
add_subdirectory(BurntConfig)

add_executable(burnt_config ${SOURCE_FILES})

target_link_libraries(burnt_config  BurntConfig gtest gtest_main ${GLIB_LIBRARIES} )
