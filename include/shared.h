#include <iostream>

template <typename T>
class MyShared {
    private:
        T* ptr_;
        int* ref_count_;
    public:
        MyShared();
        MyShared(T* ptr);
        MyShared(const MyShared<T>& other);
        MyShared<T>& operator=(const MyShared<T>& other);
        MyShared(MyShared<T>&& other) noexcept;
        MyShared<T>& operator=(MyShared<T>&& other) noexcept;
        ~MyShared();
        T* get();
        int use_count();
        static int get_ref_count();
        void reset();
};

