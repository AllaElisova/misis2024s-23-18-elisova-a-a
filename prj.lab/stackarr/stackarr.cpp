#include "stackarr.hpp"
#include <complex/complex.hpp>

StackArr::StackArr(const StackArr& other) {
	size_ = other.size_;
	data_ = new Complex[size_];
	elems_ = other.elems_;
	std::copy(other.data_, other.data_ + other.size_, data_);
	head_ = data_ + elems_;
}

StackArr& StackArr::operator=(const StackArr& other) {
	size_ = other.size_;
	data_ = new Complex[size_];
	elems_ = other.elems_;
	std::copy(other.data_, other.data_ + other.size_, data_);
	head_ = data_ + elems_;

	return *this;
}

void StackArr::Push(const Complex& complex) {
	if (size_ == 0) {
		data_ = new Complex[8];
		data_[1] = complex;
		size_ = 8;
	}

	else if (head_ + 1 > data_ + size_) {
		Complex* x = nullptr;
		x = new Complex[size_ * 2];
		std::copy(data_, data_ + size_, x);
		x[size_] = complex;
		size_ *= 2;
		std::copy(x, x + size_, data_);
		delete[] x;
	}
	else {
		data_[elems_ + 1] = complex;
	}

	++elems_;
	head_ = data_ + elems_;
}

void StackArr::Pop() noexcept {

	if (elems_ > 0) {
		head_ = nullptr;
		--elems_;
		head_ = data_ + elems_;
	}
}

bool StackArr::IsEmpty() const noexcept{
	return (elems_ == 0);
}

const Complex& StackArr::Top() {
	if (size_ == 0) {
		throw std::invalid_argument("top of empty stack");
	}
	else {
		return *(head_);
	}
}

void StackArr::Clear() noexcept {
	size_ = 0;
	elems_ = 0;
	delete[] data_;
	data_ = nullptr;
	head_ = 0;
}