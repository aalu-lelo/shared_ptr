#include <shared.h>

int main() {
    int* p = nullptr;
    {
        MyShared<int> p2(new int(20));
        p = p2.get();
        std::cout << *p << std::endl;
        p2.reset();
        std::cout << p2.use_count() << std::endl;
    }
    std::cout << *p << std::endl;
    return 0;
}
/*
shared_ptr<int> p1(new int(10));
MyShared<int> p2(new int(20));
*/