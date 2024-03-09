#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <cstddef>

#include "complex/complex.hpp"

class Complex;

class StackArr {
public:
    [[nodiscard]] StackArr() = default;
    [[nodiscard]] StackArr(const StackArr& obj) = default;
    ~StackArr() = default;
    [[nodiscard]] StackArr& operator=(const StackArr& rhs) noexcept;
    bool IsEmpty() const noexcept;
    void Push(const Complex& s);
    void Pop() noexcept;
    [[nodiscard]] const Complex& top() const;
    void Clear() noexcept;
private:
    std::ptrdiff_t size_ = 0; //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    Complex* data_ = nullptr; //!< элементы стека
};
#endif
