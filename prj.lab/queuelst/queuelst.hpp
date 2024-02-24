#pragma once

#ifndef	QUEUELST_QUEUELST_HPP
#define QUEUELST_QUEUELST_HPP

#include <cstdlib>
#include <complex/complex.hpp>

class QueueLst {
public:
	QueueLst() = default;
	QueueLst(const QueueLst& other);

	QueueLst& operator=(const QueueLst& other);

	void Push(const Complex& complex);
	void Pop() noexcept;
	const Complex& Top() const;
	Complex& Top();
	const Complex& End();
	bool IsEmpty() const noexcept;
	void Clear() noexcept;

	~QueueLst() = default;

private:
	struct Node {
		Complex v;
		Node* next = nullptr;
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif