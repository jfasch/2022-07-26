#include <iostream>

int main()
{
    int array[] = {1,2,3};
    auto [_, __, b] = array;
    std::cout << b << std::endl;
    return 0;
}
