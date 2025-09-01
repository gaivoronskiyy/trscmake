# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("trsys_CMake")

# Include sub-projects.
# add_subdirectory ("trsys_CMake")

set(CMAKE_CXX_STANDART 17)

find_package(Boost 1.66 REQUIRED)
set(openfgl_INCLUDE_DIRS "C:/Users/c/dev/freeglut/include/")
set(opengl_INCLUDE_DIRS "C:/Users/c/dev/glew-2.2.0-win32/glew-2.2.0/include/")
set(opengl_LIBRARI_DIR "C:/Users/c/dev/lopenglib")

if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
   include_directories(${opengl_INCLUDE_DIRS})
   include_directories(${openfgl_INCLUDE_DIRS})
   link_libraries(${Boost_LIBRARIES})
   link_directories(${opengl_LIBRARI_DIR})

   set(SOURCES
      Source1.cpp
   )

   add_library(trsys_CMake ${SOURCES})
   target_link_libraries(trsys_CMake LINK_PUBLIC ${Boost_LIBRARIES})
   target_link_libraries(trsys_CMake LINK_PUBLIC ${opengl_LIBRARI_DIR})

   add_executable(trsys trsys_CMake.cpp)
   target_link_libraries(trsys LINK_PUBLIC trsys_CMake)

endif()