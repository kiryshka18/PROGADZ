#include <iostream>
#include "FooString.h"

int main(){
    FooString s1((char*)"Hello");
    FooString s2((char*)", World!");

    s1.add(s2);
    s1.show(); 
    return 0;
}