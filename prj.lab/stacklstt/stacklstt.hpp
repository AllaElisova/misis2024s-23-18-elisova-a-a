#pragma once

#ifndef STACKLST_T_HPP
#define STACKLST_T_HPP

#include <cstdlib>
#include <stdexcept>
#include <algorithm>
//#include <complex/complex.hpp>

template <typename T>
class StackLstT {
public:
	//using T = Complex;

	StackLstT() = default;
	StackLstT(const StackLstT& other);
	StackLstT(StackLstT&& other) noexcept;

	StackLstT& operator= (const StackLstT& other);
	StackLstT& operator= (StackLstT&& other) noexcept;


	void Push(const T& complex);
	void Pop() noexcept;


	bool IsEmpty() const noexcept;

	T& Top();
	const T& Top() const;

	void StackLstT::Clear() noexcept;

	StackLstT::~StackLstT();

private:
	struct Node {
		T v;
		Node* next_ = nullptr;
	};

	Node* head_ = nullptr;
};

template <typename T>
StackLstT<T>::StackLstT(const StackLstT& other) {
	if (other.head_ == nullptr) {
		head_ = nullptr;
	}
	else {
		head_ = new Node;
		head_->v = other.head_->v;
		Node* next_element = other.head_;
		Node* temp = head_;

		while (next_element->next_ != nullptr) {
			temp->next_ = new Node;
			temp = temp->next_;
			next_element = next_element->next_;
			temp->v = next_element->v;
		}
		temp->next_ = nullptr;
	}
}

template <typename T>
StackLstT<T>::StackLstT(StackLstT&& other) noexcept {
	if (other.head_ == nullptr) {
		head_ = nullptr;
	}
	else {
		head_ = new Node;
		std::swap(head_, other.head_);
	}
}

template<typename T>
StackLstT<T>& StackLstT<T>::operator= (const StackLstT& other) {
	if (head_ != other.head_) {
		(*this).Clear();
		if (other.head_ == nullptr) {
			head_ = nullptr;
		}
		else {
			head_ = new Node;
			head_->v = other.head_->v;
			Node* next_element = other.head_;
			Node* temp = head_;

			while (next_element->next_ != nullptr) {
				temp->next_ = new Node;
				temp = temp->next_;
				next_element = next_element->next_;

				temp->v = next_element->v;

			}
			temp->next_ = nullptr;
		}
	}
	return *this;
}

template<typename T>
StackLstT<T>& StackLstT<T>::operator= (StackLstT&& other) noexcept {
	if (head_ != other.head_) {
		if (other.head_ == nullptr) {
			head_ = nullptr;
		}
		else {
			std::swap(head_, other.head_);
		}
	}
	return *this;
}

template <typename T>
void StackLstT<T>::Push(const T& complex) {
	Node* new_element = new Node;
	new_element->v = complex;
	new_element->next_ = head_;
	head_ = new_element;
}

template <typename T>
void StackLstT<T>::Pop() noexcept {
	if (head_ != nullptr) {
		Node* next_element;
		next_element = head_->next_;
		Node* x = head_;
		delete x;
		head_ = next_element;
	}
}

template <typename T>
bool StackLstT<T>::IsEmpty() const noexcept {
	return (head_ == nullptr);
}


template <typename T>
T& StackLstT<T>::Top() {
	if (head_ == nullptr) {
		throw std::invalid_argument("top of empty stack");
	}
	return head_->v;
}

template <typename T>
const T& StackLstT<T>::Top() const {
	if (head_ == nullptr) {
		throw std::invalid_argument("top of empty stack");
	}
	return head_->v;
}

template <typename T>
void StackLstT<T>::Clear() noexcept {
	if (head_ != nullptr) {
		Node* temp;

		while (head_ != nullptr) {
			temp = head_->next_;
			delete (head_);
			head_ = temp;
		}
	}
}

template <typename T>
StackLstT<T>::~StackLstT() {
	(*this).Clear();
}

#endif