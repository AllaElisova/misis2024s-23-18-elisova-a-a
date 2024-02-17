#pragma once

#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <cstdlib>
#include <complex/complex.hpp>

class StackLst {
public:
	StackLst() = default;
	StackLst(const StackLst& other);

	StackLst& operator = (const StackLst& other);

	void Push (const Complex& complex);
	void Pop() noexcept;
	bool IsEmpty() const noexcept;
	const Complex& Top();
	void Clear() noexcept;

	~StackLst() = default;

private:
	struct Node {
		Complex v;
		Node* next = nullptr;
	};

	Node* head_ = nullptr;
};

#endif