#include <thread>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    std::thread t([](){
        for (int i=0; i<10; i++) {
            std::cout << i << std::endl;
            std::this_thread::sleep_for(0.5s);
        }
    });

    t.join();
    return 0;
}
