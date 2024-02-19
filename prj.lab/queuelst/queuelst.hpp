#pragma once

#ifndef	QUEUELST_QUEUELST_HPP
#define QUEUELST_QUEUELST_HPP

#include <cstdlib>
#include <complex/complex.hpp>

class QueueLst {
public:
	QueueLst() = default;
	QueueLst(const QueueLst& other);

	QueueLst& operator=(const Queue& other);

	void Push(const Complex& complex);
	void Pop();
	bool IsEmpty() const noexcept;
	const Complex& Top();
	const Complex& End();
	void Clear() noexcept;

	~QueueLst() = default;

private:
	Struct Node{
		Complex v;
		Node* next = nullptr;
	}

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif