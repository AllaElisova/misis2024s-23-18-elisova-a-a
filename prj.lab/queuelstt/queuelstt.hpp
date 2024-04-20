#pragma once

#ifndef	QUEUELSTT_QUEUELSTT_HPP
#define QUEUELSTT_QUEUELSTT_HPP

#include <cstdlib>
#include <stdexcept>

template <typename T>
class QueueLstT {
public:
	QueueLstT() = default;
	QueueLstT(const QueueLstT& other);
	QueueLstT(QueueLstT&& other) noexcept;

	QueueLstT& operator=(const QueueLstT& other);
	QueueLstT& operator=(QueueLstT&& other) noexcept;

	void Push(const T& complex);
	void Pop() noexcept;
	const T& Top() const;
	T& Top();
	const T& End();
	bool IsEmpty() const noexcept;
	void Clear() noexcept;

	~QueueLstT();

private:
	struct Node {
		T v;
		Node* next = nullptr;
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

template <typename T>
QueueLstT<T>::QueueLstT(const QueueLstT& other) {
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}
	else {
		head_ = new Node;
		head_->v = other.head_->v;
		Node* next_element = other.head_;
		Node* temp = head_;

		while (next_element->next != nullptr) {
			temp->next = new Node;
			temp = temp->next;
			next_element = next_element->next;
			temp->v = next_element->v;
		}
		tail_ = temp;
		temp->next = nullptr;
	}
}

template <typename T>
QueueLstT<T>::QueueLstT(QueueLstT&& other) noexcept {
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}
	else {
		head_ = new Node;
		std::swap(head_, other.head_);
		std::swap(tail_, other.tail_);
	}
}

template <typename T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT& other) {
	(*this).Clear();
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}
	else {
		head_ = new Node;
		head_->v = other.head_->v;
		Node* next_element = other.head_;
		Node* temp = head_;

		while (next_element->next != nullptr) {
			temp->next = new Node;
			temp = temp->next;
			next_element = next_element->next;
			temp->v = next_element->v;
		}
		tail_ = temp;
		temp->next = nullptr;
	}
		return (*this);
}

template <typename T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& other) noexcept {
	if (head_ != other.head_) {
		if (other.head_ == nullptr) {
			Clear();
		}
		else {

			std::swap(head_, other.head_);
			std::swap(tail_, other.tail_);
		}
	}
	return *this;
}

template <typename T>
void QueueLstT<T>::Push(const T& complex) {
	Node* temp = new Node;
	temp->v = complex;
	temp->next = nullptr;

	if (head_ == nullptr) {
		head_ = temp;
		tail_ = temp;
	}
	else if (head_->next == nullptr) {
		tail_ = temp;
		head_->next = tail_;
	}
	else {
		tail_->next = temp;
		tail_ = temp;
	}
}

template <typename T>
void QueueLstT<T>::Pop() noexcept {
	if (head_ == nullptr) {
		tail_ = nullptr;
	}

	else if (head_->next == nullptr) {
		delete (head_);
		head_ = nullptr;
		tail_ = nullptr;
	}

	else {
		Node* temp = head_->next;
		delete (head_);
		head_ = temp;
	}
}

template <typename T>
const T& QueueLstT<T>::Top() const{
	if (head_ == nullptr) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return (head_->v);
	}
}

template <typename T>
T& QueueLstT<T>::Top() {
	if (head_ == nullptr) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return (head_->v);
	}
}

template <typename T>
const T& QueueLstT<T>::End() {
	if (tail_ == nullptr) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return (tail_->v);
	}
}

template <typename T>
bool QueueLstT<T>::IsEmpty() const noexcept{
	return (head_ == nullptr);
}

template <typename T>
void QueueLstT<T>::Clear() noexcept {
	if (head_ != nullptr) {
		Node* temp;

		while (head_ != nullptr) {
			temp = head_->next;
			delete (head_);
			head_ = temp;
		}
	}
	tail_ = nullptr;
}

template <typename T>
QueueLstT<T>::~QueueLstT() {
	(*this).Clear();
}


#endif