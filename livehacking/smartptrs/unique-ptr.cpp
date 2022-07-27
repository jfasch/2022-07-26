#include "sensors.h"
#include <iostream>
#include <memory>

using namespace std;

class HasASensor
{
public:
    HasASensor(std::unique_ptr<Sensor>&& s) : _sensor(std::move(s)) {}

    void doit()
    {
        cout << _sensor->get_temperature() << endl;
    }

private:
    std::unique_ptr<Sensor> _sensor;
};

int main()
{
    auto rs1 = std::make_unique<RandomSensor>(20, 30);
    auto rs2 = std::make_unique<RandomSensor>(2, 2);
    auto cs = std::make_unique<ConstantSensor>(666);
    HasASensor has(std::move(rs1));
    has.doit();

    // cout << rs1->get_temperature() << endl;


    return 0;
}
