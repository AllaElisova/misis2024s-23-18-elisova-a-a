#pragma once

#ifndef STACKARRT_HPP
#define STACKARRT_HPP

#include <initializer_list>
#include <cstdlib>
#include <stdexcept>
#include <memory>

template <typename T>
class StackArrT {
public:
	StackArrT() = default;
	StackArrT(const StackArrT& other);
	StackArrT(StackArrT&& other) noexcept;
	StackArrT(const std::initializer_list<T>& list);

	StackArrT& operator=(const StackArrT& other);
	StackArrT& operator=(StackArrT&& other) noexcept;
	StackArrT& operator=(const std::initializer_list<T>& list);

	void Push(const T& complex);
	void Pop() noexcept;
	bool IsEmpty() const noexcept;
	const T& Top() const;
	T& Top();
	void Clear() noexcept;

	~StackArrT();

private:
	size_t size_ = 0;
	int32_t capacity_ = 0;
	std::unique_ptr<T[]> data_ = nullptr;
	std::ptrdiff_t head_ = -1;
};


template <typename T>
StackArrT<T>::StackArrT(const StackArrT& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;

	data_ = std::make_unique<T[]>(capacity_);
	int counter = 0;

	while (counter < capacity_) {
		data_[counter] = other.data_[counter];
		++counter;
	}

	head_ = size_ - 1;
}

template <typename T>
StackArrT<T>::StackArrT(StackArrT&& other) noexcept {
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
	std::swap(head_, other.head_);
	std::swap(capacity_, other.capacity_);
}

template <typename T>
StackArrT<T>::StackArrT(const std::initializer_list<T>& list) {
	capacity_ = list.size() * 2;
	size_ = list.size();
	data_ = std::make_unique<T[]>(capacity_);

	for (T element : list) {
		++head_;
		data_[head_] = element;
	}
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT& other) {
	data_.reset();
	size_ = other.size_;
	capacity_ = other.capacity_;
	data_ = std::make_unique<T[]>(capacity_);

	int counter = 0;

	while (counter < capacity_) {
		data_[counter] = other.data_[counter];
		++counter;
	}

	head_ = size_ - 1;

	return *this;
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT&& other) noexcept {
	if (this != &other) {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		std::swap(capacity_, other.capacity_);
		std::swap(head_, other.head_);
	}
	return *this;
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const std::initializer_list <T>& list) {

	data_.reset();
	capacity_ = list.size() * 2;
	size_ = list.size();
	data_ = std::make_unique<T[]>(capacity_);

	for (T element : list) {
		++head_;
		data_[head_] = element;
	}

	return *this;
}

template <typename T>
void StackArrT<T>::Push(const T& complex) {

	if (size_ == 0) {
		data_ = std::make_unique<T[]>(8);
		data_[0] = complex;
		capacity_ = 8;
		size_ = 1;
	}

	else if (head_ + 1 >= capacity_) {

		auto x = std::make_unique<T[]>(capacity_ * 2);

		int counter = 0;

		while (counter < capacity_) {
			x[counter] = data_[counter];
			++counter;
		}

		x[size_] = complex;
		++size_;
		capacity_ *= 2;
		std::swap(data_, x);

	}
	else {
		data_[size_] = complex;
		++size_;
	}

	head_ = size_ - 1;
}

template <typename T>
void StackArrT<T>::Pop() noexcept {

	if (size_ > 0) {
		auto x = std::make_unique<T>(data_[head_]);
		x.reset();
		--size_;
		--head_;
	}
}

template <typename T>
bool StackArrT<T>::IsEmpty() const noexcept {
	return (size_ == 0);
}

template <typename T>
const T& StackArrT<T>::Top() const {
	if (size_ == 0) {
		throw std::invalid_argument("top of empty stack");
	}
	else {
		return data_[head_];
	}
}

template <typename T>
T& StackArrT<T>::Top() {
	if (size_ == 0) {
		throw std::invalid_argument("top of empty stack");
	}
	else {
		return data_[head_];
	}
}

template <typename T>
void StackArrT<T>::Clear() noexcept {
	size_ = 0;
	capacity_ = 0;
	data_.reset();
	head_ = -1;
}

template <typename T>
StackArrT<T>::~StackArrT() {
	(*this).Clear();
}

#endif
