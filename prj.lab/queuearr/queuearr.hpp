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
	QueueArr(const QueueArr& other);
	QueueArr(const std::initializer_list<Complex> list);
	QueueArr(QueueArr&& other) noexcept;

	QueueArr& operator=(const QueueArr& other);
	QueueArr& operator=(QueueArr&& other);

	bool operator==(const QueueArr& other);
	bool operator!=(const QueueArr& other);


	void Push(const Complex& complex);
	void Pop() noexcept;

	const Complex& Top() const;
	Complex& Top();
	const Complex& End() const;
	Complex& End();

	bool IsEmpty() const noexcept;
	void Clear() noexcept;



	~QueueArr() = default;

private:
	int head_ = -1;
	int tail_ = -1;
	Complex* data_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 0;
};

#endif