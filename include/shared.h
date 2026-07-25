#include <iostream>

template <typename T>
class MyShared {
    private:
        T* ptr_;
        static int ref_count_;
    public:
        MyShared();
        MyShared(T* ptr);
        MyShared(const MyShared<T>& other);
        MyShared<T>& operator=(const MyShared<T>& other);
        ~MyShared();
        T* get();
        int use_count();
        static int get_ref_count();
        void reset();
};

template <typename T>
int MyShared<T>::ref_count_ = 0; 
