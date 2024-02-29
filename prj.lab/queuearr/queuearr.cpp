#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
// #include <memory>
#include <complex/complex.hpp>
#include "queuearr.hpp"

QueueArr::QueueArr(const QueueArr& other) {
	if (other.size_ != 0) {
		if (data_ == nullptr) {
			data_ = new Complex[other.capacity_];
		}
		capacity_ = other.capacity_;
		size_ = other.size_;
		head_ = other.head_;
		tail_ = other.tail_;
		std::copy(other.data_, other.data_ + other.capacity_, data_);
	}
}

QueueArr::QueueArr(const std::initializer_list<Complex> list) {
	capacity_ = list.size() * 2;
	size_ = list.size();
	data_ = new Complex[size_];
	head_ = 0;
	std::copy(list.begin(), list.end(), data_);
	tail_ = size_ - 1;
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
	if (*this != other) {
		if (other.size_ != 0) {
			if (data_ == nullptr) {
				data_ = new Complex[other.capacity_];
			}
			capacity_ = other.capacity_;
			size_ = other.size_;
			head_ = other.head_;
			tail_ = other.tail_;
			std::copy(other.data_, other.data_ + other.capacity_, data_);
		}

		else {
			(*this).Clear();
		}
	}
	return *this;
}

bool QueueArr::operator==(const QueueArr& other) {
	int count = 0;
	if (size_ == other.size_) {
		for (int i = 0; i < size_; ++i) {
			if (data_[(head_ + i) % capacity_] != other.data_[(other.head_ + i) % other.capacity_]) {
				++count;
			}
		}
		return (count == size_);
	}
	else {
		return false;
	}
}

bool QueueArr::operator!=(const QueueArr& other) {
	return !((*this) == other);
}

void QueueArr::Push(const Complex& complex){
	if ((*this).IsEmpty()) {
		data_ = new Complex[8];
		data_[0] = complex;
		head_ = 0;
		tail_ = 0;
		size_ = 1;
		capacity_ = 8;
	}

	else if (size_ < capacity_) {
		tail_ = (tail_ + 1) % capacity_;
		++size_;
		data_[tail_] = complex;
	}

	else {
		Complex* queue = new Complex[capacity_ * 2];
		*queue = *data_;

		for (int i = 0; i < capacity_; ++i) {
			queue[i] = data_[(head_ + i) % capacity_];
		}

		data_ = queue;
		head_ = 0;
		++size_;
		tail_ = size_ - 1;
		data_[tail_] = complex;
		capacity_ *= 2;
	}
}

void QueueArr::Pop() noexcept{
	if (data_ != nullptr) {
		int temp = (head_ + 1) % capacity_;
		data_[0] = Complex(0,0);
		head_ = temp;
		--size_;
	}
}

const Complex& QueueArr::Top() const{
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return data_[head_];
	}
}

Complex& QueueArr::Top(){
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return data_[head_];
	}

}

const Complex& QueueArr::End() const {
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return data_[tail_];
	}
}

Complex& QueueArr::End(){
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return data_[tail_];
	}
}

bool QueueArr::IsEmpty() const noexcept{
	return (size_ == 0);
}

void QueueArr::Clear() noexcept{
	delete[] data_;
	data_ = nullptr;
	capacity_ = 0;
	size_ = 0;
	head_ = -1;
	tail_ = -1;
}

/* void QueueArr::Swap(QueueArr& other) {
	auto data1 = std::make_unique <Complex>(data_);
	auto data2 = std::make_unique<Complex>(other.data_);

	std::swap(data1, data2);
} */