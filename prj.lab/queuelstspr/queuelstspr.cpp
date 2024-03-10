#include "queuelstspr/queuelstspr.hpp"

#include <algorithm>
#include <stdexcept>

bool QueueLstsPr::IsEmpty() noexcept {
	return head_ == nullptr;
}

void QueueLstsPr::Clear() {
	if (!IsEmpty()) {
		head_ = nullptr;
		tail_ = nullptr;
	}
}

void QueueLstsPr::Sort(double* data_) {
	size = data_.size();
	for (int i = 0, i != size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (data_[j] > data_[j + 1]) {
				std::swap(data_[j], data_[j + 1]);
			}
		}
	}
}
double QueueLstsPr::Top() {
	if (IsEmpty()) {
		throw std::logic_error("QueueLstsPr - try get top from empty queue.");
	}
	return head_->val;
}

void QueueLstsPr::Pop() {
	if (!IsEmpty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
	if (IsEmpty()) {
		tail_ = nullptr;
	}
}


void QueueLstsPr::Push(const double& val) {
	if (IsEmpty()) {
		tail_ = new Node{ val };
		head_ = tail_;
	}
	else {
		tail_->next = new Node{ val };
		tail_ = tail_->next;
	}
	data_.push_back(val);
	Sort(double* data_);
}
QueueLstsPr& QueueLstsPr::operator=(const QueueLst& rhs) {
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

/*QueueLstsPr& operator=(const QueueLstsPr& obj);*/
