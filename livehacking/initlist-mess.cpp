#include <iostream>
#include <vector>

using namespace std;

struct point
{
    point(int x, int y) : x(x), y(y) {}
    point() = default;
    int x{0};
    int y{0};
};


int main()
{
    point p1(1,2);
    point p2{1,2};

    point p;
    cout << p.x << ' ' << p.y << endl;

    std::vector<int> v1(2, 666);
    cout << "---v1:" << endl;
    for (int i: v1)
        cout << i << endl;
    
    std::vector<int> v2{2, 666};
    cout << "---v2:" << endl;
    for (int i: v2)
        cout << i << endl;
    

    return 0;
}
