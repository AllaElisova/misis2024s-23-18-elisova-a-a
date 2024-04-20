#pragma once

#ifndef	QUEUEARRT_QUEUEARRT_HPP
#define QUEUEARRT_QUEUEARRT_HPP

#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>
#include <memory>
// #include <complex/complex.hpp>

template<typename T>
class QueueArrT {
public:
	QueueArrT() = default;
	QueueArrT(const QueueArrT& other);
	QueueArrT(QueueArrT&& other) noexcept;
	QueueArrT(const std::initializer_list <T>& list);

	QueueArrT& operator=(const QueueArrT& other);
	QueueArrT& operator=(QueueArrT&& other) noexcept;
	QueueArrT& operator=(const std::initializer_list <T>& list);


	void Push(const T& complex);
	void Pop() noexcept;

	const T& Top() const;
	T& Top();
	const T& End() const;
	T& End();

	bool IsEmpty() const noexcept;
	void Clear() noexcept;


	~QueueArrT();

private:
	std::ptrdiff_t head_ = -1;
	std::ptrdiff_t tail_ = -1;
	std::unique_ptr <T[]> data_ = nullptr;
	uint32_t size_ = 0;
	uint32_t capacity_ = 0;
};


template <typename T>
QueueArrT<T>::QueueArrT(const QueueArrT& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;

		if (other.size_ != 0) {
			int counter = 0;
			data_ = std::make_unique<T[]>(capacity_);

			while (counter < capacity_) {
				data_[counter] = other.data_[counter];
				++counter;
			}

			head_ = other.head_;
			tail_ = other.tail_;
		}
}

template <typename T>
QueueArrT<T>::QueueArrT(QueueArrT&& other) noexcept {
	std::swap (data_, other.data_);
	std::swap (capacity_, other.capacity_);
	std::swap (size_, other.size_);
	std::swap (head_, other.head_);
	std::swap (tail_ , other.tail_);
}

template <typename T>
QueueArrT<T>::QueueArrT(const std::initializer_list<T>& list) {
	capacity_ = list.size() * 2;
	size_ = list.size();

	if (size_ != 0) {
		data_ = std::make_unique<T[]>(capacity_);
		head_ = 0;

		for (T element : list) {
			++tail_;
			data_[tail_] = element;
		}
	}
}

template <typename T>
QueueArrT<T>& QueueArrT<T>::operator=(const QueueArrT& other) {
	if (this != &other) {

		if (other.size_ != 0) {

			data_.reset();
			capacity_ = other.capacity_;
			size_ = other.size_;
			data_ = std::make_unique<T[]>(capacity_);

			int counter = 0;

			while (counter < capacity_) {
				data_[counter] = other.data_[counter];
				++counter;
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

template <typename T>
QueueArrT<T>& QueueArrT<T>::operator=(QueueArrT&& other) noexcept{
	if (this != &other) {
			capacity_ = other.capacity_;
			size_ = other.size_;
			head_ = other.head_;
			tail_ = other.tail_;
			std::swap(data_, other.data_);
	}
	return *this;
}

template <typename T>
QueueArrT<T>& QueueArrT<T>::operator=(const std::initializer_list <T>& list) {
	(*this).Clear();

	capacity_ = list.size() * 2;
	size_ = list.size();

	if (list.size() != 0) {
		data_ = std::make_unique<T[]>(capacity_);
		head_ = 0;

		for (T element : list) {
			++tail_;
			data_[tail_] = element;
		}
	}
	return *this;
}

template <typename T>
void QueueArrT<T>::Push(const T& complex){
	if ((*this).IsEmpty()) {
	
		data_ = std::make_unique<T[]>(8);
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
		
		auto queue = std::make_unique<T[]>(capacity_ * 2);

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

template <typename T>
void QueueArrT<T>::Pop() noexcept{
	if ((data_ != nullptr) && (size_ > 0)) {
		int temp = (head_ + 1) % capacity_;
		//T elem;
		//data_[0] = elem;
		head_ = temp;
		--size_;
	}
}

template <typename T>
const T& QueueArrT<T>::Top() const{
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return data_[head_];
	}
}

template <typename T>
T& QueueArrT<T>::Top(){
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return data_[head_];
	}

}

template <typename T>
const T& QueueArrT<T>::End() const {
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return data_[tail_];
	}
}

template <typename T>
T& QueueArrT<T>::End() {
	if ((*this).IsEmpty()) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return data_[tail_];
	}
}

template <typename T>
bool QueueArrT<T>::IsEmpty() const noexcept{
	return (size_ == 0);
}

template <typename T>
void QueueArrT<T>::Clear() noexcept{
	data_.reset();
	capacity_ = 0;
	size_ = 0;
	head_ = -1;
	tail_ = -1;
}

template <typename T>
QueueArrT<T>::~QueueArrT() {
	(*this).Clear();
}

#endif