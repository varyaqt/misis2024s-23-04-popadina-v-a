#include "queuelst/queuelst.hpp"

#include <stdexcept>

QueueLst::QueueLst(QueueLst&& obj) noexcept {
    head_ = obj.head_;
    tail_ = obj.tail_;
    obj.head_ = nullptr;
    obj.tail_ = nullptr;
}

QueueLst& QueueLst::operator=(QueueLst&& rhs) noexcept {
    if (this != &rhs) {
        Clear();
        head_ = rhs.head_;
        tail_ = rhs.tail_;
        rhs.head_ = nullptr;
        rhs.tail_ = nullptr;
    }
    return *this;
}

bool QueueLst::IsEmpty() const noexcept {
    return nullptr == head_;
}

void QueueLst::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (IsEmpty()) {
        tail_ = nullptr;
    }
}

void QueueLst::Push(const Complex& val) {
    if (IsEmpty()) {
        tail_ = new Node{ val };
        head_ = tail_;
    }
    else {
        tail_->next = new Node{ val };
        tail_ = tail_->next;
    }
}

Complex& QueueLst::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top from empty queue.");
    }
    return head_->v;
}

const Complex& QueueLst::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top form empty queue.");
    }
    return head_->v;
}

void QueueLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
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
        if (tail_ != nullptr) tail_->next = nullptr;
    }
    return *this;
}
