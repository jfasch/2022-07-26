#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        memory = new char[10];
    }
    virtual ~Base()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        delete[] memory;
    }

    virtual const char* describe() const { return "Base"; }

private:
    char* memory;
};

class Derived : public Base
{
public:
    Derived()
    {
        memory = new char[10];
    }
    virtual ~Derived()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        delete[] memory;
    }

    virtual const char* describe() const { return "Derived"; }

private:
    char* memory;
};


int main()
{
    Base* b = new Derived;
    cout << b->describe() << endl;
    delete b;

    return 0;
}
