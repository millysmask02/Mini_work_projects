#include <iostream>
#include <thread>
#include <windows.h>


void foo(int n) {
    for (size_t i = 0; i < n; i++) {
        std::cout << __FUNCTION__ << ": " << i << std::endl;
        Sleep(700);
    }
}

void bar(int n) {
    for (size_t i = 0; i < n; i++) {
        std::cout << __FUNCTION__ << ": " << i << std::endl;
        Sleep(700);
    }
}

int main() {

    std::thread t1(foo, 10);
    std::thread t2(bar, 10);

    if (t1.joinable()) {
        t1.join();
    }


    system("pause");

    return 0;
}