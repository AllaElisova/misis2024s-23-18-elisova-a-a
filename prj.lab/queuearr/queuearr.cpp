#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
// #include <memory>
#include <complex/complex.hpp>
#include "queuearr.hpp"

QueueArr::QueueArr(const std::initializer_list<Complex> list) {
	capacity_ = list.size() * 2;
	size_ = list.size();
	data_ = new Complex[size_];
	head_ = data_;
	std::copy(list.begin(), list.end(), data_);
	tail_ = head_ + size_ - 1;
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
	if ((other.head_ != nullptr) && (*this != other)) {
		capacity_ = other.capacity_;
		size_ = other.size_;

		std::copy(other.head_, other.tail_, head_);
		tail_ = head_ + size_ - 1;

		Complex* temp1 = data_;
		while (temp1 < head_) {
			(*temp1) = Complex(0, 0);
			++temp1;
		}

		Complex* temp2 = head_ + size_;
		while (temp2 < head_ + capacity_) {
			(*temp2) = Complex(0, 0);
			++temp2;
		}
	}
	return *this;
}

QueueArr QueueArr::operator=(const QueueArr other) {
	if ((other.head_ != nullptr) && (*this != other)) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		std::copy(other.head_, other.tail_, head_);
		tail_ = head_ + size_ - 1;

		Complex* temp = head_ + size_;

		while (temp < head_ + capacity_) {
			(*temp) = Complex(0, 0);
			++temp;
		}

		Complex* temp2 = head_ + size_;
		while (temp2 < head_ + capacity_) {
			(*temp2) = Complex(0, 0);
			++temp2;
		}
	}
	return *this;
}

bool QueueArr::operator==(const QueueArr& other) {
	bool equal = true;

	if (capacity_ == other.capacity_) {
		for (int i = 0; i < size_; ++i) {
			if (*(data_ + i) != *(other.data_ + i)) {
				equal = false;
			}
		}
	}

	return equal;
}

bool QueueArr::operator!=(const QueueArr& other) {
	return !((*this) == other);
}

void QueueArr::Push(const Complex& complex){
	if ((*this).IsEmpty()) {
		data_ = new Complex[8];
		*data_ = complex;
		head_ = data_;
		tail_ = data_;
		size_ = 1;
		capacity_ = 8;
	}

	else if (size_ < capacity_) {

		if (tail_ + 1 < data_ + capacity_) {
			++tail_;
			(*tail_) = complex;
		}
		else {
			tail_ = tail_ + 1 - capacity_;
			
		}
		++size_;
		(*tail_) = complex;
	}

	else {

		Complex* queue = new Complex[capacity_ * 2];
		*queue = *head_;

		for (int i = 0; i < capacity_; ++i) {
			if (head_ + i < data_ + capacity_) {
				queue[i] = *(head_ + i);
			}
			else {
				queue[i] = *(head_ + i - capacity_);
			}
		}

		data_ = queue;
		head_ = data_;
		tail_ = data_ + size_ ;
		*tail_ = complex;
		++size_;
		capacity_ *= 2;
	}
}

void QueueArr::Pop() noexcept{
	if (head_ != nullptr) {
		Complex* temp = data_ + (int(tail_ - 1) % capacity_);
		tail_ = temp;
		--size_;
	}
}

const Complex& QueueArr::Top() const{
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return (*head_);
	}
}

Complex& QueueArr::Top(){
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return (*head_);
	}

}

const Complex& QueueArr::End() const {
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return (*tail_);
	}
}

Complex& QueueArr::End(){
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return (*tail_);
	}
}

bool QueueArr::IsEmpty() const noexcept{
	return (head_ == nullptr);
}

void QueueArr::Clear() noexcept{
	while (size_ > 0) {
		Complex* temp = head_;
		++head_;
		delete(temp);
		--size_;
	}
	capacity_ = 0;
	head_ = nullptr;
	tail_ = nullptr;
}

/* void QueueArr::Swap(QueueArr& other) {
	auto data1 = std::make_unique <Complex>(data_);
	auto data2 = std::make_unique<Complex>(other.data_);

	std::swap(data1, data2);
} */