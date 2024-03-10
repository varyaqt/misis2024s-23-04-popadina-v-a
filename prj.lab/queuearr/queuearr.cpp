#include "queuearr/queuearr.hpp"

#include <algorithm>
#include<memory>
#include <stdexcept>

QueueArr& operator=(const QueueArr& obj) {
    if (this != obj) {
        if (capacity_ < obj.capacity_) {
            data_ = std::make_unique<Complex[]>(obj.capacity_);
            capacity_ = obj.capacity_;
        }
        head_ = 0;
        if (obj.tail_ > obj.head_) {
            std::copy(obj.data_.get() + obj.head_, obj.data_.get() + obj.tail_, data_.get());
            tail_ = obj.tail_ - obj.head_;
        }
        else {
            std::copy(obj.data_.get() + obj.head_, obj.data_.get() + obj.capacity_, data_.get());
            std::copy(obj.data_.get(), obj.data_.get() + obj.tail_, data_.get() + (obj.capacity_ - obj.head_));
            tail_ = obj.capacity_ = obj.head_ + obj.tail_;
        }
    }
    return *this;
}
bool QueueArr::IsEmpty() noexcept {
    return nullptr == head_;
}
void Pop() noexcept {
    if (!IsEmpty()) {
        tail_ -= 1;
    }
}
void Clear() noexcept {
    head_ = nullptr;
    tail_ = nullptr;
}

Complex& Top() {
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("QueueArr - try get top form empty queue.");
    }
}

void Push(const Complex& obj) {
    if (data_ == nullptr) {
        size_ = 10;
        data_ = new Complex[size_];
    }
    else if (size_ ==  i_top + 1) {
        auto buf = new Complex(size_ * 2);
        std::copy(data_, data_ + size_, buf);
        std::swap(data_, buf);
        delete[] buf;
        size_ *= 2;
    }
    data_[++i_top_] = obj;
}
