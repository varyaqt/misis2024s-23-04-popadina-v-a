#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <memory>
#include "complex/complex.hpp"

class Complex;

class StackArr {
public:
    [[nodiscard]] StackArr();
    [[nodiscard]] StackArr(const StackArr& rhs);
    [[nodiscard]] StackArr(StackArr&& rhs) noexcept;
    ~StackArr() = default;
    [[nodiscard]] StackArr& operator=(const StackArr& rhs) noexcept;
    [[nodiscard]] StackArr& operator=(StackArr&& rhs) noexcept;
    bool IsEmpty() const noexcept;
    void Push(const Complex& s);
    void Pop() noexcept;
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
    void Clear() noexcept;
private:
    std::ptrdiff_t size_ = 0; //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    std::unique_ptr<Complex[]> data_ = std::make_unique<Complex[]>(size_);
};
#endif
