#include "../includes/type.hpp"

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
    try {
        if (dynamic_cast<A*>(p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(p))
            std::cout << "C" << std::endl;
        else
            throw std::exception();
    }
    catch(const std::exception& e) {
        std::cerr << "Error: exception caught" << std::endl;
    };
    
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::bad_cast&) {}
}

int main()
{
    Base *a;
    a = generate();
    identify(a);
    identify(*a);
    delete(a);
}