#include <iostream>

template <typename T>
class MyShared {
    private:
        T* ptr_;
        int ref_count_;
    public:
        MyShared(T* ptr) : ptr_(ptr) {
            ref_count_ = 1;
        }

        T* get() { 
            return ptr_; 
        }

        int use_count() { return ref_count_; }

        void reset() {
            ref_count_--;
            if(ref_count_ == 0) {
                delete ptr_;
                ptr_ = nullptr;
            }
        }

        ~MyShared() { 
            std::cout << "Destructor called" << std::endl;
            delete ptr_; 
        }
};