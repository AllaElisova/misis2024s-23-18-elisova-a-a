#include "stacklst.hpp"
#include <complex/complex.hpp>

StackLst::StackLst(const StackLst& other) {

	Node node;
	Node* next_element = other.head_;

	while (next_element != nullptr) {
		node = *next_element;
		head_ = &(node);
		next_element = (*next_element).next;
	}

	next_element = nullptr;
}

StackLst& StackLst::operator=(const StackLst& other) {
	
	Node node;
	Node* next_element = other.head_;

	while (next_element != nullptr) {
		node = *next_element;
		head_ = &(node);
		next_element = (*next_element).next;
	}

	next_element = nullptr;

	return *this;
}

void StackLst::Push(const Complex& complex) {
	Node* new_element = new Node;
	new_element -> v = complex;
	new_element -> next = head_;
	head_ = new_element;
} 

void StackLst::Pop() noexcept{
	if (head_ != nullptr) {
		Node* next_element;
		next_element = (*head_).next;
		delete (head_);
		head_ = next_element;
		next_element = nullptr;
	}
}

bool StackLst::IsEmpty() const noexcept {
		return (head_ == nullptr);
}

const Complex& StackLst::Top() {
	if (head_ == nullptr) {
		throw std::invalid_argument("top of empty stack");
	}
	else {
		return (*head_).v;
	}
}

void StackLst::Clear() noexcept {
	while (head_ != nullptr){
		Node* next_element = (*head_).next;
		delete (head_);
		head_ = nullptr;
		head_ = next_element;
	}
}