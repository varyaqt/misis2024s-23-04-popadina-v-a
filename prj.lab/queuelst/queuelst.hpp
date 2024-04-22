#pragma once
#ifndef QUEUELST_QUEUELST
#define QUEUELST_QUEUELST

#include "complex/complex.hpp"

#include <cstddef>

class QueueLst {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& obj) = default;
    QueueLst(QueueLst&& obj) noexcept;
    QueueLst& operator=(QueueLst&& rhs) noexcept;
    ~QueueLst() = default;
    [[nodiscard]] QueueLst& operator=(const QueueLst&) = default;
    [[nodiscard]] bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const Complex& val);
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
    void Clear() noexcept;
private:
    struct Node {
        Complex val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;   //!< 
    Node* tail_ = nullptr;   //!< 
};
#endif
