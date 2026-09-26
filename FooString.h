#pragma once
#include <iostream>
#include <cstring>

class FooString{
    char* buf;
public:
    FooString(char* puv);
    ~FooString();
    void show();
    void add(FooString str);
};