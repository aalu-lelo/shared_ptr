#include <shared.h>

template <typename T>
MyShared<T>::MyShared() : ptr_(nullptr){
}

template <typename T>
MyShared<T>::MyShared(T* ptr) : ptr_(ptr) {
    ref_count_ = new int(1);
}

template <typename T>
MyShared<T>::MyShared(const MyShared<T> &other) : ptr_(other.ptr_) {
    ref_count_ = other.ref_count_;
    (*ref_count_)++;
}

template <typename T>
MyShared<T>& MyShared<T>::operator=(const MyShared<T>& other) {
    (*ref_count_)--;
    if(*ref_count_ == 0) {
        delete ptr_;
        delete ref_count_;
    }

    ptr_ = other.ptr_;
    ref_count_ = other.ref_count_;
    (*ref_count_)++;
    return *this;
}

template <typename T>
MyShared<T>::MyShared(MyShared<T>&& other) noexcept : ptr_(other.ptr_) {
    ptr_ = other.ptr_;
    ref_count_ = other.ref_count_;
    other.ptr_ = nullptr;
}

template <typename T>
MyShared<T>& MyShared<T>::operator=(MyShared<T>&& other) noexcept {
    (*ref_count_)--;
    if(*ref_count_ == 0) {
        delete ptr_;
        delete ref_count_;
    }
    ptr_ = other.ptr_;
    ref_count_ = other.ref_count_;
    other.ptr_ = nullptr;
    return *this;
}

template <typename T>
T* MyShared<T>::get() { 
    return ptr_;
}

template <typename T>
int MyShared<T>::use_count() { return *ref_count_; }

template <typename T>
void MyShared<T>::reset() {
    if(ref_count_) (*ref_count_)--;
    ref_count_ = nullptr;
    ptr_ = nullptr;
}

template <typename T>
MyShared<T>::~MyShared() { 
    if(ref_count_) (*ref_count_)--;
    ref_count_ = nullptr;
    ptr_ = nullptr;
}

template class MyShared<int>;

