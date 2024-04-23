#pragma once
#ifndef QUEUEARRT_HPP
#define QUEUEARRT_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#include <cstddef>

template<class T>
class QueueArrT {
public:
    [[nodiscard]] QueueArrT() = default;
    [[nodiscard]] QueueArrT(const QueueArrT& rhs);
    ~QueueArrT() = default;
    [[nodiscard]] QueueArrT& operator=(const QueueArrT& rhs);
    [[nodiscard]] QueueArrT& operator=(QueueArrT&& d) noexcept;
    [[nodiscard]] QueueArrT(QueueArrT&& d) noexcept;

    void Push(const T& c);
    void Pop() noexcept;
    void Clear() noexcept;
    [[nodiscard]] T& Top();
    [[nodiscard]] const T& Top() const;
    bool IsEmpty() const noexcept;
    std::ptrdiff_t Count() const;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t head_ = -1;
    std::ptrdiff_t tail_ = -1;
    std::unique_ptr<T[]> data_ = std::make_unique<T[]>(capacity_);
};

#endif

template<class T>
QueueArrT<T>::QueueArrT(const QueueArrT& rhs) {
    if (rhs.head_ != -1) {
        data_ = std::make_unique<T[]>(rhs.capacity_);
        capacity_ = rhs.capacity_;
        head_ = 0;
        if (rhs.tail_ > rhs.head_) {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_, data_.get());
            tail_ = rhs.tail_ - rhs.head_;
        }
        else {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.capacity_, data_.get());
            std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_, data_.get() + (rhs.capacity_ - rhs.head_));
            tail_ = rhs.capacity_ - rhs.head_ + rhs.tail_;
        }
    }
}

template<class T>
QueueArrT<T>::QueueArrT(QueueArrT&& d) noexcept {
    std::swap(capacity_, d.capacity_);
    std::swap(data_, d.data_);
    std::swap(tail_, d.tail_);
    std::swap(head_, d.head_);
}

template<class T>
QueueArrT<T>& QueueArrT<T>::operator=(QueueArrT&& d) noexcept {
    if (this != &d) {
        std::swap(capacity_, d.capacity_);
        std::swap(data_, d.data_);
        std::swap(tail_, d.tail_);
        std::swap(head_, d.head_);
    }
    return *this;
}

template<class T>
QueueArrT<T>& QueueArrT<T>::operator=(const QueueArrT& rhs) {
    if (this != &rhs) {
        if (capacity_ < rhs.capacity_) {
            data_ = std::make_unique<T[]>(rhs.capacity_);
            capacity_ = rhs.capacity_;
        }
        head_ = 0;
        if (rhs.tail_ > rhs.head_) {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_, data_.get());
            tail_ = rhs.tail_ - rhs.head_;
        }
        else {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.capacity_, data_.get());
            std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_, data_.get() + (rhs.capacity_ - rhs.head_));
            tail_ = rhs.capacity_ - rhs.head_ + rhs.tail_;
        }
    }
    return *this;
}

template<class T>
void QueueArrT<T>::Push(const T& c) {
    if (head_ == -1) {
        capacity_ = 8;
        data_ = std::make_unique<T[]>(capacity_);
        head_ = 0;
        tail_ = 0;
    }
    data_[tail_] = c;
    if (head_ == (tail_ + 1) % capacity_) {
        std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity_ * 2);
        std::copy(data_.get() + head_, data_.get() + capacity_, newData.get());
        if (tail_ < head_) {
            std::copy(data_.get(), data_.get() + tail_, newData.get() + (capacity_ - head_));
        }
        std::swap(data_, newData);
        capacity_ *= 2;
        head_ = 0;
        tail_ = capacity_ / 2;
    }
    else {
        tail_ = (tail_ + 1) % capacity_;
    }
}

template<class T>
void QueueArrT<T>::Pop() noexcept {
    if (head_ != -1) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % capacity_;
        }
        if (head_ == tail_) {
            head_ = -1;
        }
    }
}

template<class T>
T& QueueArrT<T>::Top() {
    if (head_ < 0) {
        throw std::logic_error("QueueArrT Is Empty!");
    }
    else {
        return data_[head_];
    }
}

template<class T>
const T& QueueArrT<T>::Top() const {
    if (head_ < 0) {
        throw std::logic_error("QueueArrT Is Empty!");
    }
    else {
        return data_[head_];
    }
}

template<class T>
bool QueueArrT<T>::IsEmpty() const noexcept {
    return head_ < 0;
}

template<class T>
std::ptrdiff_t QueueArrT<T>::Count() const {
    return (head_ == -1) ? 0 : (tail_ + capacity_ - head_) % capacity_;
}

template<class T>
void QueueArrT<T>::Clear() noexcept {
    head_ = -1;
}
