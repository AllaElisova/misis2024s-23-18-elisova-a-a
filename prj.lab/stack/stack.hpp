#pragma once

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& other);

	StackArr& operator=();

	void Push(const Complex& complex);
	void Pop() noexcept;
	bool IsEmpty() const noexcept;
	const Complex& Top();

	~StackArr() = default;

private:
	int32_t size_{ 0 };
	int32_t capacity_{ 0 };
	float* data_ = nullptr;
};

#endif
