PROJECT(avalon_base)
cmake_minimum_required(VERSION 2.4)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(FindPkgConfig)

# Enable -Wall for compilers that know it
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-Wall" CXX_SUPPORTS_WALL)
if (CXX_SUPPORTS_WALL)
    add_definitions (-Wall)
endif (CXX_SUPPORTS_WALL)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

find_package(Eigen2 REQUIRED)
include_directories(${EIGEN2_INCLUDE_DIR})

pkg_check_modules(BASE REQUIRED "base-types")
include_directories(${BASE_INCLUDE_DIRS})
link_directories(${BASE_LIBRARY_DIRS})

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}")

CONFIGURE_FILE(avalon_base-types.pc.in avalon_base-types.pc @ONLY)
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/avalon_base DESTINATION include)
INSTALL(FILES ${CMAKE_BINARY_DIR}/avalon_base-types.pc DESTINATION lib/pkgconfig)

CONFIGURE_FILE(Doxyfile.in Doxyfile @ONLY)
ADD_CUSTOM_TARGET(doc doxygen Doxyfile)
