


//mylib.cpp
#include "mylib.h" 
#include <string> 
#include <array> 


#include <iostream>
#include <boost/array.hpp>
#include <asio.hpp>

//void print_string(const std::string & a)  {
//    std::cout <<__FILE__ << __LINE__ << " content of a:"  << a << std::endl;
//}


void print_string(const char * msg )  {

    std::string myMsg = std::string("hello ") + msg; 

    std::cout <<__FILE__ << __LINE__ << " content of a:"  << myMsg << std::endl;
}
uint64_t start_timer(uint64_t interval){

    asio::io_context io; 
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.wait();
    std::cout << "Hello, world!" << std::endl;

    return 0;
}
using asio::ip::tcp;
uint64_t start_client(const char *host, uint32_t port )
{
    try
    {
        

        asio::io_context io_context;

        tcp::resolver resolver(io_context);
        char portStr[32] = {0};
        sprintf(portStr,"%d", port); 
        tcp::resolver::results_type endpoints = resolver.resolve(host, portStr);

        tcp::socket socket(io_context);
        asio::connect(socket, endpoints);

        for (;;)
        {
            std::array<char, 128> buf;
            asio::error_code error;

            size_t len = socket.read_some(asio::buffer(buf), error);

            if (error == asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw asio::system_error(error); // Some other error.

            std::cout.write(buf.data(), len);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}
