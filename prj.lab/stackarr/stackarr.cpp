#include "stackarr.hpp"

StackArr::StackArr() {
    capacity_ = 5;
    data_ = new Complex[capacity_];
}

StackArr::StackArr(const StackArr& obj) {
    size_ = obj.size_;
    capacity_ = obj.capacity_;
    data_ = new Complex[size_];
    std::copy(obj.data_, obj.data_ + obj.size_, data_);
}

StackArr& StackArr::operator=(const StackArr& rhs) noexcept {
    if (rhs.size_ > capacity_) {
        capacity_ = rhs.size_;
        delete[] data_;
        data_ = new Complex(rhs.size_);
    }
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
    size_ = rhs.size_;
    return *this;
}

bool StackArr::isEmpty() noexcept {
    if (size_ == 0) {
        return true;
    }
    else {
        return false;
    }
}

void StackArr::pop() noexcept {
    if (size_ > 0) {
        size_--;
    }
}

void StackArr::push(const Complex& s) {
    if (size_ + 1 > capacity_) {
        Complex* newData = new Complex[capacity_ + 5];
        std::copy(data_, data_ + size_, newData);
        delete[] data_;
        data_ = newData;
        capacity_ += 5;
    }
    size += 1;
    data_[size_ - 1] = s;
}

Complex& StackArr::top() {
    if (size_ > 0) {
        return data_[size_ - 1];
    }
    else {
        throw std::out_of_range("Error! Now stack is empty!\n")
    }
}
