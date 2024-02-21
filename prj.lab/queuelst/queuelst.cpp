#include <cstdlib>
#include <complex/complex.hpp>
#include "queuelst.hpp"

QueueLst::QueueLst(const QueueLst& other) {
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

QueueLst& QueueLst::operator=(const QueueLst& other) {
	(*this).Clear();
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

	return (*this);
}

void QueueLst::Push(const Complex& complex) {
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

void QueueLst::Pop() {
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

const Complex& QueueLst::Top() {
	if (head_ == nullptr) {
		throw std::invalid_argument("top of empty queue");
	}
	else {
		return (head_->v);
	}
}

const Complex& QueueLst::End() {
	if (tail_ == nullptr) {
		throw std::invalid_argument("end of empty queue");
	}
	else {
		return (tail_->v);
	}
}

bool QueueLst::IsEmpty() const noexcept{
	return (head_ == nullptr);
}

void QueueLst::Clear() noexcept {
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


