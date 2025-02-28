#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

class WrongClass : public Base {};

Base* generate()
{
    int random = rand() % 3;
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer is of type A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer is of type B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer is of type C\n";
    else
        std::cout << "Unknown pointer type\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference is of type A\n";
        return;
    } catch (std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference is of type B\n";
        return;
    } catch (std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference is of type C\n";
        return;
    } catch (std::exception& e) {}
    std::cout << "Unknown reference type\n";
}

int main()
{
    srand(time(NULL));

    Base* randomBase = generate();
    
    //normal cast
    identify(randomBase);
    identify(*randomBase);
    delete randomBase;

    //bad cast
    Base *wrongobj = new WrongClass();
    identify(wrongobj);
    identify(*wrongobj);
    delete wrongobj;

    return 0;
}
