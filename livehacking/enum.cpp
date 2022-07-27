#include <iostream>

using namespace std;

enum class E1 : bool {
    ONE,
    TWO,
};

enum class E2 {
    ONE,
    TWO
};

int main()
{
    auto e = E1::ONE;
    cout << sizeof(e) << endl;
    return 0;
}
