#include <iostream>

template <typename T>
class MyShared {
    private:
        T* ptr_;
        static int ref_count_;
    public:
        MyShared(T* ptr);
        MyShared(MyShared<T>& other);
        ~MyShared();
        T* get();
        int use_count();
        void reset();
};

template <typename T>
int MyShared<T>::ref_count_ = 0; 
