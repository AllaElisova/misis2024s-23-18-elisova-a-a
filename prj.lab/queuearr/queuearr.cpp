/*#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
#include <complex/complex.hpp>
#include "queuearr.hpp"

QueueArr::QueueArr(const std::initializer_list<Complex> list) {
	capacity_ = list.size() * 2;
	size_ = list.size();
	data_ = new Complex[size_];
	std::copy(list.begin(), list.end(), data_);
	head_ = data_;
	tail_ = data_ + size_ - 1;
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
	size_ = other.size_;
	std::copy(other.head_, other.tail_, head_);
	tail_ = head_ + size_ - 1;

	Complex* temp = head_ + size_;
	while ()
	return *this;
}

bool QueueArr::QueueArr::operator==(const QueueArr& other) {

} */