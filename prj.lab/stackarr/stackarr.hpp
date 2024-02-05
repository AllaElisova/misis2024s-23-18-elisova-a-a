#pragma once

#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& other);

	StackArr& operator = ();

	void Push(const Complex& complex);
	void Pop() noexcept;
	bool IsEmpty() noexcept;
	const Complex& Top();

	~StackArr() = default;
};

