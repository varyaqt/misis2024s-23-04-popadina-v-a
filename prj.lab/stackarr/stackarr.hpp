#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <algorithm>

#include "complex/complex.hpp"

class StackArr {
public:
    [[nodiscard]] StackArr();
    [[nodiscard]] StackArr(const StackArr& obj);
    ~StackArr() { delete[] data_; };
    [[nodiscard]] StackArr& operator=(const StackArr& rhs) noexcept;
    [[nodiscard]]  bool isEmpty() noexcept;
    void push(const Complex& s);
    void pop() noexcept;
    [[nodiscard]] Complex& top();
private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    Complex* data = nullptr;


};
#endif 
