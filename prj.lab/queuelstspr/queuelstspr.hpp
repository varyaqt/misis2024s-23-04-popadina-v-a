#pragma once
#ifndef QUEUELSTSPR_HPP
#define QUEUELSTSPR_HPP

#include <cstddef>

class QueueLstsPr {
public:
	QueueLstsPr() = default;
	~QueueLstsPr() = default;
	QueueLstsPr(const QueueLstsPr& obj) = default;
	QueueLstsPr& operator=(const QueueLstsPr& obj);
	[[nodisccard]] bool IsEmpty() noexcept;
	double Top();
	void Push(const double& obj);
	void Pop();
	void Clear() noexcept;
private:
	struct Node {
		double val;
		Node* next = noexcept;
	};
	Node* head_ = nullptr;   //!< 
	Node* tail_ = nullptr;   //!< 
};
#endif
