#include "complex/complex.hpp"
#include "stackarr/stackarr.hpp"

#include <algorithm>
#include <stdexcept>

bool StackArr::isEmpty() const noexcept {
    return 0 <= i_top_;
}

void StackArr::pop() noexcept {
    if (!isEmpty()) {
        i_top_ -= 1;
    }
}
void StackArr::clear() noexcept {
    i_top_ = -1;
}

void StackArr::push(const Complex& s) {
    if (data_ == nullptr) {
        size_ = 10;
        data_ = new Complex[size_];
    }
    else if (size_ == i_top_ + 1) {
        auto buf = new Complex(size_ * 2);
        std::copy(data_, data_ + size_, buf);
        std::swap(data_, buf);
        delete[] buf;
        size_ *= 2;
    }
    data_[++i_top_] = s;
}

const Complex& StackArr::top() const{
    if (i_top_ < 0) {
        throw std::logic_error("StackArr - try get top form empty stack.");
    }
    return data_[i_top_];
}

StackArr& StackArr::operator=(const StackArr& rhs) noexcept {
    if (rhs.size_ > size_) {
        size_ = rhs.size_;
        delete[] data_;
        data_ = new Complex(rhs.size_);
    }
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
    size_ = rhs.size_;
    return *this;
}
