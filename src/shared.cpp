#include <shared.h>


template <typename T>
MyShared<T>::MyShared(T* ptr) : ptr_(ptr) {
    ref_count_ = 1;
}

template <typename T>
MyShared<T>::MyShared(MyShared<T> &other) : ptr_(other.ptr_) {
    ref_count_++;
}

template <typename T>
T* MyShared<T>::get() { 
    return ptr_;
}

template <typename T>
int MyShared<T>::use_count() { return ref_count_; }

template <typename T>
void MyShared<T>::reset() {
    ref_count_--;
    if(ref_count_ == 0) {
        delete ptr_;
        ptr_ = nullptr;
    }
}

template <typename T>
MyShared<T>::~MyShared() { 
    ref_count_--;
    if(ref_count_ == 0) {
        delete ptr_;
        ptr_ = nullptr;
    }
}

template class MyShared<int>;

