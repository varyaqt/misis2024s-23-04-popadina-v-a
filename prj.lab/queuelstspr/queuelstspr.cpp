#include "queuelstspr/queuelstspr.hpp"

#include <algorithm>
#include <stdexcept>

bool IsEmpty() noexcept {
	return head_ == nullptr;
}

void Clear() {
	if (!IsEmpty()) {
		head_ = nullptr;
		tail_ = nullptr;
	}
}

void Sort(double* data_) {
	size = data_.size();
	for (int i = 0, i != size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (data_[j] > data_[j + 1]) {
				std::swap(data_[j], data_[j + 1]);
			}
		}
	}
}
double Top() {
	if (IsEmpty()) {
		throw std::logic_error("QueueLstsPr - try get top from empty queue.");
	}
	return head_->val;
}

void Pop() {
	if (!IsEmpty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
	if (IsEmpty()) {
		tail_ = nullptr;
	}
}



void QueueLstSPr::Push(const double& val) {
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

/*QueueLstsPr& operator=(const QueueLstsPr& obj);*/
