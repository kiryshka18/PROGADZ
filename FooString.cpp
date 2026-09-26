#include "FooString.h"

FooString::FooString(char* puv){
    if(puv){
        buf = new char[std::strlen(puv) + 1];
        std::strcpy(buf, puv);
    }else{
        buf = new char[1];
        buf[0] = '\0';
    }
}

FooString::~FooString(){
    delete[] buf;
}

void FooString:: show(){
    if(buf){
        std::cout << buf << std::endl;
    }
}

void FooString::add(FooString str){
    if(!str.buf) return;

    size_t current_len = std::strlen(buf);
    size_t add_len = std::strlen(str.buf);
    char* new_buf = new char[current_len + add_len + 1];
    std::strcpy(new_buf, buf);
    std::strcat(new_buf, str.buf); 
    delete[] buf;
    buf = new_buf;
}