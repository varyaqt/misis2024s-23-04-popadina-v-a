#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <cstddef>

#include "complex/complex.hpp"

class Complex;

class QueueArr {
public:
    QueueArr() = default;
    QueueArr(const QueueArr& obj) = default;
    ~QueueArr() = default;
    QueueArr& operator=(const QueueArr& obj) noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const Complex& obj);
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
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
};
