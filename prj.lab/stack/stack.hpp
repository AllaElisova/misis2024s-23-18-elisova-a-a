#pragma once

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <complex/complex.hpp>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& other);

	StackArr& operator=(const StackArr& other);

	void Push(const Complex& complex);
	void Pop() noexcept;
	bool IsEmpty() const noexcept;
	const Complex& Top();

	~StackArr() = default;

private:
	int32_t size_{ 0 };
	int32_t elems_ = 0;
	Complex* data_ = nullptr;
	Complex* head_ = 0;
};

#endif
