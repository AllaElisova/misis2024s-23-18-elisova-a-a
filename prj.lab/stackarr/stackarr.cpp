#include <initializer_list>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include "stackarr.hpp"
#include <complex/complex.hpp>

StackArr::StackArr(const StackArr& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	//data_ = new Complex[size_];
	data_ = std::make_unique<Complex[]>(capacity_);
	//std::copy(other.data_, other.data_ + other.size_, data_);
	int counter = 0;

	while (counter < capacity_) {
		data_[counter] = other.data_[counter];
		++counter;
	}

	head_ = size_ - 1;
}

StackArr::StackArr(const std::initializer_list<Complex>& list){
	capacity_ = list.size() * 2;
	size_ = list.size();
	data_ = std::make_unique<Complex[]>(capacity_);

	for (Complex element : list) {
		++head_;
		data_[head_] = element;
	}

	//head_ = data_ + elems_ - 1;
}

StackArr& StackArr::operator=(const StackArr& other) {
	data_.reset();
	size_ = other.size_;
	capacity_ = other.capacity_;
	//data_ = new Complex[size_];
	data_ = std::make_unique<Complex[]>(capacity_);
	
	//std::copy(other.data_, other.data_ + other.size_, data_);
	int counter = 0;

	while (counter < capacity_) {
		data_[counter] = other.data_[counter];
		++counter;
	}

	head_ = size_ - 1;

	return *this;
}

StackArr& StackArr::operator=(const std::initializer_list <Complex>& list){
	//delete[] data_;
	data_.reset();
	capacity_ = list.size() * 2;
	size_ = list.size();
	//data_ = new Complex[size_];
	data_ = std::make_unique<Complex[]>(capacity_);
	//std::copy(list.begin(), list.end(), data_);

	for (Complex element : list) {
		++head_;
		data_[head_] = element;
	}

	return *this;
}

void StackArr::Push(const Complex& complex) {

	if (size_ == 0) {
		//data_ = new Complex[8];
		data_ = std::make_unique<Complex[]>(8);
		data_[0] = complex;
		capacity_ = 8;
		
	}

	else if (head_ + 1 > capacity_) {

		//x = new Complex[size_ * 2];
		//std::copy(data_, data_ + size_, x);

		auto x = std::make_unique<Complex[]>(size_ * 2);
		
		int counter = 0;

		while (counter < capacity_) {
			x[counter] = data_[counter];
			++counter;
		}

		x[capacity_] = complex;
		capacity_ *= 2;
		//std::copy(x, x + size_, data_);
		//delete[] x;

		counter = 0;

		std::swap(data_, x);
		
	}
	else {
		data_[size_] = complex;
	}
	
	head_ = size_;
	++size_;
}

void StackArr::Pop() noexcept {

	if (size_ > 0) {
		data_[head_] = Complex(0, 0);
		--size_;
		head_ = size_ - 1;
	}
}

bool StackArr::IsEmpty() const noexcept{
	return (size_ == 0);
}

const Complex& StackArr::Top() const {
	if (size_ == 0) {
		throw std::invalid_argument("top of empty stack");
	}
	else {
		return data_[head_];
	}
}

Complex& StackArr::Top() {
	if (size_ == 0) {
		throw std::invalid_argument("top of empty stack");
	}
	else {
		return data_[head_];
	}
}

void StackArr::Clear() noexcept {
	size_ = 0;
	capacity_ = 0;
	data_.reset();
	head_ = -1;
}

StackArr::~StackArr() {
	data_.reset();
}
