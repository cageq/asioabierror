


//mylib.cpp
#include "mylib.h" 
#include <string> 
#include <iostream> 

void print_string(const std::string & a)  {
    std::cout <<__FILE__ << __LINE__ << " content of a:"  << a << std::endl;
}
