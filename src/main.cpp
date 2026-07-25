#include <shared.h>

int main() {
    /*
    Simple test to check if the shared pointer implementation is working correctly.
    int* global = nullptr;
    {
        MyShared<int> p1(new int(20));
        global = p1.get();
        std::cout << *global << std::endl;
        p1.reset();
        std::cout << p1.use_count() << std::endl;
    }*/

    // Test to check if the copy constructor is working correctly.
    {
        MyShared<int> p2(new int(30));
        std::cout << p2.use_count() << std::endl;
        MyShared<int> p3(p2);
        std::cout << p2.use_count() << std::endl;
        std::cout<< *p2.get() << std::endl;
        std::cout << *p3.get() << std::endl;
    }
    return 0;
}