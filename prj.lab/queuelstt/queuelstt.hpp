#pragma once
#ifndef QUEUELSTT_HPP
#define QUEUELSTT_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>

template<class T>
class QueueLstT {
public:
    [[nodiscard]] QueueLstT() = default;
    [[nodiscard]] QueueLstT(const QueueLstT& rhs);
    [[nodiscard]] QueueLstT(QueueLstT&& rhs) noexcept;
    ~QueueLstT();
    [[nodiscard]] QueueLstT& operator=(const QueueLstT& rhs);
    [[nodiscard]] QueueLstT& operator=(QueueLstT&& rhs) noexcept;

    void Push(const T& c);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] T& Top();
    [[nodiscard]] const T& Top() const;
    void Clear() noexcept;

private:
    struct Node {
        T v;
        Node* next = nullptr;
        Node(const T& val) : v(val) {}
        ~Node() = default;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

template<class T>
QueueLstT<T>::QueueLstT(const QueueLstT& rhs) {
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->v);
        head_ = newNode;
        tail_ = newNode;
        Node* next = rhs.head_->next;
        Node* cur = tail_;
        while (next != nullptr) {
            Node* newNode = new Node(next->v);
            if (head_->next == nullptr) {
                head_->next = newNode;
            }
            tail_ = newNode;
            cur->next = newNode;
            next = next->next;
            cur = cur->next;
        }
    }
}

template<class T>
QueueLstT<T>::QueueLstT(QueueLstT&& rhs) noexcept {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
        std::swap(tail_, rhs.tail_);
    }
    return *this;
}

template<class T>
QueueLstT<T>::~QueueLstT() {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
    tail_ = nullptr;
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT& rhs) {
    if (this != &rhs) {
        Node* vs = rhs.head_;
        Node* tvs = head_;
        Node* pr;
        while (vs != nullptr) {
            if (tvs != nullptr) {
                tvs->v = vs->v;
            }
            else {
                Node* newNode = new Node(vs->v);
                if (head_ == nullptr) {
                    head_ = newNode;
                    tail_ = newNode;
                }
                else {
                    tail_->next = newNode;
                    tail_ = tail_->next;
                }
                tvs = newNode;
            }
            pr = tvs;
            tvs = tvs->next;
            vs = vs->next;
        }
        while (tvs != nullptr) {
            Node* delete_future = tvs;
            tvs = tvs->next;
            delete delete_future;
        }
        tail_ = pr;
        tail_->next = nullptr;
    }
    return *this;
}

template<class T>
void QueueLstT<T>::Push(const T& c) {
    Node* newNode = new Node(c);
    if (head_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
    }
    else if (head_ != nullptr) {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

template<class T>
void QueueLstT<T>::Pop() noexcept {
    if (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
    if (head_ == nullptr) {
        tail_ = nullptr;
    }
}

template<class T>
bool QueueLstT<T>::IsEmpty() const noexcept {
    return (head_ == nullptr);
}

template<class T>
T& QueueLstT<T>::Top() {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

template<class T>
const T& QueueLstT<T>::Top() const {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

template<class T>
void QueueLstT<T>::Clear() noexcept {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
    tail_ = nullptr;
}

#endif
