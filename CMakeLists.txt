cmake_minimum_required(VERSION 3.13)
project (abidemo VERSION 0.7 )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -O2    -Wno-unused-function  ")



include_directories(include)
link_directories(bin)
link_directories(lib)

include_directories(mylib)



If ( CMAKE_CXX_COMPILER_VERSION VERSION_LESS  9.0 )
add_library(mylib SHARED mylib/mylib.cpp) 
#target_compile_options(mylib PRIVATE  -D_GLIBCXX_USE_CXX11_ABI=1) 

else()

add_executable(myapp  app/myapp.cpp)
target_link_libraries(myapp mylib)

endif()
