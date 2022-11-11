


//mylib.cpp
#include "mylib.h" 
#include <string> 
#include <iostream> 

//void print_string(const std::string & a)  {
//    std::cout <<__FILE__ << __LINE__ << " content of a:"  << a << std::endl;
//}


void print_string(const char * msg )  {

    std::string myMsg = std::string("hello ") + msg; 

    std::cout <<__FILE__ << __LINE__ << " content of a:"  << myMsg << std::endl;
}
