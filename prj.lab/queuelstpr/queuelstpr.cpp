/*#include "queuelstpr.hpp"

QueueLstPr::QueueLstPr(const QueueLstPr& other) {
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}

	else {
		head_ = new Node;
		head_->v = other.head_->v;

		Node* next_elem = other.head_;
		Node* temp = head_;


		while (next_elem->next != nullptr) {
			temp->next = new Node;
			next_elem = next_elem->next;
			temp->v = next_elem->v;
		}
		tail_ = temp;
		temp->next = nullptr;
	}
}

QueueLstPr::QueueLstPr(QueueLstPr&& other) {
	head_ = other.head_;
	tail_ = other.tail_;

	other.head_ = nullptr;
	other.tail_ = nullptr;
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& other) {
	(*this).Clear();
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}
	else {
		head_ = 
	}
}
*/