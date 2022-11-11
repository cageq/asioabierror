#ifndef __MYLIB_H__
#define __MYLIB_H__
#include <string> 

//__attribute__((visibility ("default"))) void print_string(const std::string & a);
__attribute__((visibility ("default"))) void print_string(const char *  a);

__attribute__((visibility ("default"))) uint64_t start_timer(uint64_t interval);
__attribute__((visibility ("default"))) uint64_t start_client(const char *host, uint32_t port );


#endif

