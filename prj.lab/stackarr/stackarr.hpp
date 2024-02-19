#pragma once

#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <initializer_list>
#include <cstdlib>
#include <complex/complex.hpp>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& other);
	StackArr(const std::initializer_list<Complex>& list);

	StackArr& operator=(const StackArr& other);
	StackArr& operator=(const std::initializer_list<Complex>& list);

	void Push(const Complex& complex);
	void Pop() noexcept;
	bool IsEmpty() const noexcept;
	const Complex& Top();
	void Clear() noexcept;

	~StackArr();

private:
	size_t size_ = 0;
	int32_t elems_ = 0;
	Complex* data_ = nullptr;
	Complex* head_ = 0;
};

#endif
