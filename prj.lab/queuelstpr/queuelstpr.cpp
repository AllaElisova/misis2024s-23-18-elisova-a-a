/*#include "queuelstpr.hpp"

QueueLstPr::QueueLstPr(const QueueLstPr& other) {
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}

	else {
		head_ = new Node;
		head_->value = other.head_->value;

		Node* next_elem = other.head_;
		Node* temp = head_;


		while (next_elem->next_ != nullptr) {
			temp->next_ = new Node;
			next_elem = next_elem->next_;
			temp->value = next_elem->value;
		}
		tail_ = temp;
		temp->next_ = nullptr;
	}
}

QueueLstPr::QueueLstPr(QueueLstPr&& other) {
	head_ = other.head_;
	tail_ = other.tail_;

	other.head_ = nullptr;
	other.tail_ = nullptr;
}

QueueLstPr::QueueLstPr(const std::initializer_list<float>& list) {
	for (float elem : list) {
		Push(elem);
	}
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& other) {
	(*this).Clear();
	if (other.head_ == nullptr) {
		head_ = nullptr;
		tail_ = nullptr;
	}
	else {
		head_ = new Node;
		head_->value = other.head_->value;
		Node* next_elem = other.head_;
		Node* temp = head_;


		while (next_elem->next_ != nullptr) {
			temp->next_ = new Node;
			next_elem = next_elem->next_;
			temp->value = next_elem->value;
		}
		tail_ = temp;
		temp->next_ = nullptr;
	}

	return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& other) {
	head_ = other.head_;
	tail_ = other.tail_;

	other.head_ = nullptr;
	other.tail_ = nullptr;

	return *this;
}

QueueLstPr& QueueLstPr::operator=(const std::initializer_list<float> list) {
	for (float elem : list) {
		Push(elem);
	}

	return *this;
}

bool QueueLstPr::IsEmpty() const noexcept{
	return (head_ == nullptr);
}

void QueueLstPr::Push(const float& elem) {
	if ((*this).IsEmpty()) {
		head_ = new Node;
		head_->value = elem;
	}

	else {
		Node* temp = head_;
		Node* prev_temp = nullptr;

		while () {
			prev_temp = ;

			if (elem < temp->value) {
				temp = temp->next_;

			}
		}
	}
}

void QueueLstPr::Pop() {
	if ((*this).IsEmpty() == false) {

		Node* temp = head_;

		if (temp->count != 0) {
			--(temp->count);
		}

		else if (temp->next_ != nullptr) {
			head_ = temp->next_;
			delete temp;
			temp = nullptr;

		}

		else {
				delete head_;
				head_ = nullptr;
			}
		}
}


QueueLstPr::~QueueLstPr() {
	(*this).Clear();
}


*/