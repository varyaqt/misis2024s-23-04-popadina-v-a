#pragma once
#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <cstddef>

class QueueLstPr {
public:
	QueueLstPr() = default;
	~QueueLstPr() = default;
	QueueLstPr(const QueueLstPr& obj) = default;
	QueueLstPr& operator=(const QueueLstPr& obj);
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
