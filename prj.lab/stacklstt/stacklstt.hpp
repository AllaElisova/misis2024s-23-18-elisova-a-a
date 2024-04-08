#pragma once

#ifndef STACKLST_T_HPP
#define STACKLST_T_HPP

#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <complex/complex.hpp>

class StackLstT {
public:
	using T = Complex;

	StackLstT() = default;

	StackLstT(const StackLstT& other) {
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

	StackLstT(StackLstT&& other) noexcept {
		if (other.head_ == nullptr) {
			head_ = nullptr;
		}
		else {
			head_ = new Node;
			std::swap(head_, other.head_);
		}
	}

	StackLstT& operator= (const StackLstT& other) {
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

	StackLstT& operator= (StackLstT&& other) noexcept {
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


	void Push(const T& complex) {
		Node* new_element = new Node;
		new_element->v = complex;
		new_element->next_ = head_;
		head_ = new_element;

	}

	void Pop() noexcept {
		if (head_ != nullptr) {
			Node* next_element;
			next_element = head_->next_;
			Node* x = head_;
			delete x;
			head_ = next_element;
		}
	}


	bool StackLstT::IsEmpty() const noexcept {
		return (head_ == nullptr);
	}

	const T& StackLstT::Top() const {
		if (head_ == nullptr) {
			throw std::invalid_argument("top of empty stack");
		}
		else {
			return head_->v;
		}
	}

	T& StackLstT::Top() {
		if (head_ == nullptr) {
			throw std::invalid_argument("top of empty stack");
		}
		else {
			return head_->v;
		}
	}

	void StackLstT::Clear() noexcept {
		if (head_ != nullptr) {
			Node* temp;

			while (head_ != nullptr) {
				temp = head_->next_;
				delete (head_);
				head_ = temp;
			}
		}
	}

	StackLstT::~StackLstT() {
		(*this).Clear();
	}


private:
	struct Node {
		T v;
		Node* next_ = nullptr;
	};

	Node* head_ = nullptr;
};

#endif