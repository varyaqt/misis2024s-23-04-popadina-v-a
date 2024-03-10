#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <cstddef>

#include "complex/complex.hpp"

class Complex;

class QueueArr {
public:
    QueueArr() = default;
    QueueArr(const QueueArr& obj) = default;
    ~QueueArr() = default;
    QueueArr& operator=(const QueueArr& obj);
    [[nodiscard]] bool IsEmpty() noexcept;
    void Pop() noexcept;
    void Push(const Complex& obj);
    [[nodiscard]] Complex& Top();
    void Clear() noexcept;
private:
    struct Node {
        Complex obj;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    Complex* data_ = nullptr;
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
};
