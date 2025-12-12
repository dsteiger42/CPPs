#include "../includes/type.hpp"

Base * generate(void)
{
	int i;

	//std::srand(std::time(0));
	i = std::rand() % 3;

    switch(i)
    {
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
    std::cout << &p << std::endl;
}

void identify(Base& p)
{

}

int main()
{

}