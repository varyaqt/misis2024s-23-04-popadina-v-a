#pragma once
#ifndef QUEUELSTT_HPP
#define QUEUELSTT_HPP

#include <cstddef>
template<class T>
class QueueLstT {
public:
    QueueLstT() = default;
    QueueLstT(const QueueLstT& obj) = default;
    QueueLstT(QueueLstT&& obj) noexcept;
    QueueLstT& operator=(QueueLstT&& rhs) noexcept;
    ~QueueLstT() = default;
    [[nodiscard]] QueueLstT& operator=(const QueueLstT&) = default;
    [[nodiscard]] bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const T& val);
    [[nodiscard]] T& Top();
    [[nodiscard]] const T& Top() const;
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

template<class T>
QueueLstT<T>::QueueLstT(QueueLstT&& obj) noexcept {
    head_ = obj.head_;
    tail_ = obj.tail_;
    obj.head_ = nullptr;
    obj.tail_ = nullptr;
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& rhs) noexcept {
    if (this != &rhs) {
        Clear();
        head_ = rhs.head_;
        tail_ = rhs.tail_;
        rhs.head_ = nullptr;
        rhs.tail_ = nullptr;
    }
    return *this;
}

template<class T>
bool QueueLstT<T>::IsEmpty() const noexcept {
    return nullptr == head_;
}

template<class T>
void QueueLstT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (IsEmpty()) {
        tail_ = nullptr;
    }
}

template<class T>
void QueueLstT<T>::Push(const T& val) {
    if (IsEmpty()) {
        tail_ = new Node{ val };
        head_ = tail_;
    }
    else {
        tail_->next = new Node{ val };
        tail_ = tail_->next;
    }
}

template<class T>
T& QueueLstT<T>::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top from empty queue.");
    }
    return head_->val;
}

template<class T>
const T& QueueLstT<T>::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top form empty queue.");
    }
    return head_->val;
}

template<class T>
void QueueLstT<T>::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT& rhs) {
    if (this != &rhs) {
        Node* vs = rhs.head_;
        Node* tvs = head_;
        Node* pr = nullptr;
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
        if (tail_ != nullptr)tail_->next = nullptr;
    }
    return *this;
}
