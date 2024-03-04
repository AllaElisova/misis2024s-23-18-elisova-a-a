#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>
#include <memory>
#include <complex/complex.hpp>
#include "queuearr.hpp"

QueueArr::QueueArr(const QueueArr& other) {
	if (other.size_ != 0) {
		if (data_ == nullptr) {
			data_ = std::make_unique<Complex[]> (other.size_);
		}
		capacity_ = other.capacity_;
		size_ = other.size_;
		head_ = 0;
		tail_ = 0;

		while (tail_ < other.size_) {
			data_[tail_] = other.data_[tail_];
			++tail_;
		}

		head_ = other.head_;
		tail_ = other.tail_;
		//std::copy(other.data_, other.data_ + other.capacity_, data_);

	}
}

QueueArr::QueueArr(QueueArr&& other) noexcept {
	capacity_ = other.capacity_;
	size_ = other.size_;
	std::swap(data_, other.data_);
	// data_ = other.data_;
	head_ = other.head_;
	tail_ = other.tail_;
}

QueueArr::QueueArr(const std::initializer_list<Complex> list) {
	capacity_ = list.size() * 2;
	size_ = list.size();

	if (list.size() != 0) {
		data_ = std::make_unique<Complex[]>(list.size());
		head_ = 0;

		for (Complex element : list) {
			++tail_;
			data_[tail_] = element;
		}
	}
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
	if (*this != other) {

		if (other.size_ != 0) {

			if (data_ == nullptr) {
				data_ = std::make_unique<Complex[]> (other.capacity_);
			}

			capacity_ = other.capacity_;
			size_ = other.size_;
			head_ = 0;
			tail_ = 0;
			// std::copy(other.data_, other.data_ + other.capacity_, data_);
			while (tail_ < capacity_) {
				data_[tail_] = other.data_[tail_];
				++tail_;
			}
			head_ = other.head_;
			tail_ = other.tail_;
		}

		else {
			(*this).Clear();
		}
	}
	return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& other){
	if (*this != other) {
			capacity_ = other.capacity_;
			size_ = other.size_;
			head_ = other.head_;
			tail_ = other.tail_;
			//data_ = other.data_;
			//other.data_ = nullptr;
			std::swap(data_, other.data_);
	}
	return *this;
}

QueueArr& QueueArr::operator=(const std::initializer_list <Complex> list) {
	(*this).Clear();

	capacity_ = list.size() * 2;
	size_ = list.size();

	if (list.size() != 0) {
		data_ = std::make_unique<Complex[]>(list.size());

		head_ = 0;
		for (Complex element : list) {
			++tail_;
			data_[tail_] = element;
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
	
		data_ = std::make_unique<Complex[]>(8);
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
		
		auto queue = std::make_unique<Complex[]>(capacity_ * 2);
		queue[0] = data_[0];

		for (int i = 0; i < capacity_; ++i) {
			queue[i] = data_[(head_ + i) % capacity_];
		}

		std::swap(data_, queue);
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

Complex& QueueArr::End() {
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
	data_.reset();
	data_ = nullptr;
	capacity_ = 0;
	size_ = 0;
	head_ = -1;
	tail_ = -1;
}

