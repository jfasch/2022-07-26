#include "sensors.h"
#include <iostream>

using namespace std;

template <typename T> class AutoPtr
{
public:
    AutoPtr(T* t) : _pointer(t) {}
    AutoPtr(AutoPtr<T>& other)
    {
        _pointer = other._pointer;
        other._pointer = nullptr;
    }
    ~AutoPtr() { delete _pointer; }

    AutoPtr& operator=(AutoPtr& other)
    {
        if (this != &other) {
            _pointer = other._pointer;
            other._pointer = nullptr;
        }
        return *this;
    }
    
    T* operator->() { return _pointer; }
    const T* operator->() const { return _pointer; }
    T& operator*() { return *_pointer; }
    const T& operator*() const { return *_pointer; }

private:
    T* _pointer;
};


class HasASensor
{
public:
    HasASensor(AutoPtr<Sensor> s) : _sensor(s) {}

    void doit()
    {
        cout << _sensor->get_temperature() << endl;
    }

private:
    AutoPtr<Sensor> _sensor;
};

int main()
{
    auto* rsp = new RandomSensor(2, 666);
    AutoPtr<Sensor> rs(rsp);
    HasASensor has(rs);
    has.doit();

//    std::cout << rs->get_temperature() << std::endl;

    return 0;
}
