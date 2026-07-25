#include <iostream>

template <typename T>
class MyShared {
    private:
        T* ptr_;
        int ref_count_;
    public:
        MyShared(T* ptr);
        ~MyShared();
        T* get();
        int use_count();
        void reset();
};