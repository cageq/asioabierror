


# asio abi error demo 


## mylib 
mylib  build using gcc 8 on centos 7 

~ → ldd --version 
ldd (GNU libc) 2.17


 ~ → gcc --version 
gcc (GCC) 8.3.1 20190311 (Red Hat 8.3.1-3)
Copyright (C) 2018 Free Software Foundation, Inc.




## app 
app build using gcc 11 on ubuntu 22.04.1


ldd --version 
ldd (Ubuntu GLIBC 2.35-0ubuntu3.1) 2.35


gcc --version 
gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0



## run app 
on  ubuntu  

crash : 



For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from bin/myapp...
(gdb) r
Starting program: /home/arthur/abitest/bin/myapp 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7c26e48 in asio::detail::object_pool<asio::detail::epoll_reactor::descriptor_state>::alloc<bool> (arg=<optimized out>, this=0x7fffffffdef8) at /home/arthur/abitest/opt/asio-1.22.1/include/asio/detail/object_pool.hpp:116
116         object_pool_access::prev(o) = 0;
(gdb) bt
#0  0x00007ffff7c26e48 in asio::detail::object_pool<asio::detail::epoll_reactor::descriptor_state>::alloc<bool> (arg=<optimized out>, this=0x7fffffffdef8)
    at /home/arthur/abitest/opt/asio-1.22.1/include/asio/detail/object_pool.hpp:116
#1  asio::detail::epoll_reactor::allocate_descriptor_state (this=0x7fffffffde30) at /home/arthur/abitest/opt/asio-1.22.1/include/asio/detail/impl/epoll_reactor.ipp:657
#2  asio::detail::epoll_reactor::register_descriptor (descriptor_data=@0x7fffffffdf40: 0x5555555641ba <asio::detail::service_base<asio::detail::signal_set_service>::id>, descriptor=6, this=0x7fffffffde30)
    at /home/arthur/abitest/opt/asio-1.22.1/include/asio/detail/impl/epoll_reactor.ipp:154
#3  asio::detail::reactive_socket_service_base::do_open (ec=std::error_code = {std::_V2::error_category: 0}, protocol=6, type=1, af=2, impl=..., this=<optimized out>)
    at /home/arthur/abitest/opt/asio-1.22.1/include/asio/detail/impl/reactive_socket_service_base.ipp:186
#4  asio::detail::reactive_socket_service<asio::ip::tcp>::open (ec=std::error_code = {std::_V2::error_category: 0}, protocol=..., impl=..., this=<optimized out>)
    at /home/arthur/abitest/opt/asio-1.22.1/include/asio/detail/reactive_socket_service.hpp:128
#5  asio::basic_socket<asio::ip::tcp, asio::any_io_executor>::connect (ec=std::error_code = {std::_V2::error_category: 0}, peer_endpoint=..., this=0x7fffffffdf30)
    at /home/arthur/abitest/opt/asio-1.22.1/include/asio/basic_socket.hpp:895
#6  asio::connect<asio::ip::tcp, asio::any_io_executor, asio::ip::basic_resolver_iterator<asio::ip::tcp>, asio::detail::default_connect_condition> (s=..., begin=..., end=..., connect_condition=..., 
    ec=std::error_code = {std::_V2::error_category: 0}) at /home/arthur/abitest/opt/asio-1.22.1/include/asio/impl/connect.hpp:242
#7  0x00007ffff7c27e5f in asio::connect<asio::ip::tcp, asio::any_io_executor, asio::ip::basic_resolver_results<asio::ip::tcp> > (s=..., endpoints=..., ec=std::error_code = {std::_V2::error_category: 0})
    at /home/arthur/abitest/opt/asio-1.22.1/include/asio/impl/connect.hpp:126
#8  0x00007ffff7c1deb5 in asio::connect<asio::ip::tcp, asio::any_io_executor, asio::ip::basic_resolver_results<asio::ip::tcp> > (endpoints=..., s=...) at /home/arthur/abitest/opt/asio-1.22.1/include/asio/impl/connect.hpp:113
#9  start_client (host=host@entry=0x555555560117 "127.0.0.1", port=port@entry=8888) at /home/arthur/abitest/mylib/mylib.cpp:49
#10 0x0000555555559ad9 in main () at /home/arthur/abitest/app/myapp.cpp:24


