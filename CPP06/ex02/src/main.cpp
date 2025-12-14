#include "../includes/type.hpp"
/*
Dynamic cast behaviour:
- Cast to Pointer - Returns null on failure
- Cast to Reference - Throws exception on failure

NOTE: 
    References throw an exception, because they can never be NULL.
    A NULL basically means "point to nothing". References need to refer to something. 
*/
Base * generate(void)
{
	int i;

	std::srand(std::time(0));
	i = std::rand() % 3;

    switch(i) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
// catch(...) means catch any exception, regardless of the type
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...) {}
}

int main()
{
    Base *a;
    a = generate();
    identify(a);
    identify(*a);
    delete(a);
}