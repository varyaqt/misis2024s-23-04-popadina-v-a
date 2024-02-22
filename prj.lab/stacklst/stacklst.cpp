#include "complex/complex.hpp"
#include "stacklst/stacklst.hpp"

#include <algorithm>
#include <stdexcept>

bool StackLst::IsEmpty() noexcept {
    return (head_ == nullptr);
}

void StackLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* copy = head_;
        delete head_;
        head_ = copy->next;
    }
}
void StackLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

StackLst::~StackLst() {
    Clear();
}

void StackLst::Push(const Complex& s) {
    Node* copy = *head_;
    head_ = new Node();
    head_->next = copy;
}

const Complex& StackLst::Top() const {
    if (IsEmpty()) {
        throw::std::logic_error("List is empty");
    }
    else {
        return head_->val;
    }
}

StackLst& StackLst::operator=(const StackLst& s) noexcept {
    Clear(); 
    Node* go_back_s = s.head_;
    head_ = new Node(go_back_s->val);
    Node* go_back = head_;
    while (go_bacl_s->next != nullptr) {
        go_back_s = go_back_s->next;
        go_back->next = new Node(go_back_s->val);
        go_back = go_back->next;
    }
    return *this;
}
