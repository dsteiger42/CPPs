#ifndef TYPE_HPP
#define TYPE_HPP

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <typeinfo> 

class Base
{
    public:
        virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif