


#include <ctime>
#include <iostream>
#include <string>
#include <asio.hpp>
#include "mylib.h" 
#include <string>



using asio::ip::tcp;

std::string make_daytime_string()
{
    using namespace std; // For time_t, time and ctime;
    time_t now = time(0);
    return ctime(&now);
}

int main()
{
    start_client("127.0.0.1", 8888); 
    std::string myStr = "From my app" ; 
    print_string(myStr.c_str() );

    try
    {
        asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 5800));

        for (;;)
        {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::string message = make_daytime_string();

            asio::error_code ignored_error;
            asio::write(socket, asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

