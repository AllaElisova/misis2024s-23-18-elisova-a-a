#pragma once

#ifndef	QUEUEARR_QUEUEARR_HPP
#define QUEUEARR_QUEUEARR_HPP

#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
#include <complex/complex.hpp>

class QueueArr {
public:
	QueueArr() = default;
	QueueArr(const QueueArr& other) = default;
	QueueArr(const std::initializer_list<Complex> list);

	QueueArr& operator=(const QueueLst& other);

	void Push(const Complex& complex);
	void Pop() noexcept;
	const Complex& Top() const;
	Complex& Top();
	const Complex& End();
	bool IsEmpty() const noexcept;
	void Clear() noexcept;

	~QueueArr() = default;

private:
	Complex* data_ = nullptr;
	Complex* tail_ = nullptr;
	size_t size_ = 0;
	size_t capacity = 0;
};