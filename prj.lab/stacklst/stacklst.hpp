#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <cstddef>

#include "complex/complex.hpp"

class Complex;

class StackLst {
public:
    [[nodiscard]] StackLst() = default;
    [[nodiscard]] StackLst(const StackLst& s) = default;
    ~StackLst() = default;
    [[nodiscard]] StackLst& operator=(const StackLst& s) noexcept;
    bool IsEmpty() noexcept;
    void Push(const Complex& num);
    void Pop() noexcept;
    [[nodiscard]] const Complex& Top() const;
    void Clear() noexcept;
private:
    struct Node {
        Complex val;
        Node* next;
        Node(const Complex& data) : val(data), next(nullptr) {}
        ~Node() = default;
    };
    Node* head_ = nullptr;
};
#endif
