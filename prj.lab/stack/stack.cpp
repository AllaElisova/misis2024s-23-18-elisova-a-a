#include "stack.hpp"
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
		++size_;
	}

	else if (head_ + 1 > data_ + size_) {
		Complex* x = nullptr;
		x = new Complex[size_ * 2];
		std::copy(data_, data_ + size_, x);
		std::copy(x, x + size_, data_);
		size_ *= 2;
	}
	else {
		++size_;
	}
	Complex y = complex;
	head_ = &y;
	++elems_;
}

void StackArr::Pop() noexcept {
	delete(data_ + elems_);
	if (elems_ > 0) {
		--elems_;
		head_ -= 1;
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