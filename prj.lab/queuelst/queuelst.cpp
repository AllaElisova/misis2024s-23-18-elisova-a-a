#include <cstdlib>
#include <complex/complex.hpp>
#include "queuelst.hpp"

QueueLst::QueueLst(const QueueLst& other) {
	head_ = new Node;
	head_->v = other.head_->v;
	Node* next_element = other.head_;
	Node* temp = head_;

	(while next_element->next != nullptr) {
		temp->next = new Node;
		temp = temp->next;
		next_element = next_element->next;
		temp->v = next_element->v;
	}
	tail_ = temp;
	temp->next = nullptr;
}

QueueLst::operator=(const QueueLst& other) {
	(*this).Clear();

}

void QueueLst::Push(const Complex& complex) {

}

void QueueLst::Pop() {

}

bool QueueLst::IsEmpty() const noexcept{
	return (head_ == nullptr);
}

Complex& QueueLst::Top() {

}

Complex& QueueLst::End() {

}

void QueueLst::Clear() noexcept {

}


