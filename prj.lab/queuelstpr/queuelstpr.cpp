#include "queuelstpr.hpp"
/*
QueueLstPr::QueueLstPr(const QueueLstPr& other) {
	if (other.root_ == nullptr) {
		root_ = nullptr;

	}

	else {
	
		Node* root_temp = other.root_;
	
		root_ = other.root_
		Node* temp = other.root_->left_;

		while (temp->right_ != nullptr) {
			temp->right_ = new Node;
			next_elem = next_elem->right_;
			temp->value = next_elem->value;
		}

		temp->right_ = nullptr;
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

void QueueLstPr::copy_node(Node* cur_node, const Node* other_node) noexcept {
	if (other_node != nullptr) {

		if (cur_node == nullptr) {
			cur_node = new Node;
			cur_node->value_ = other_node->value_;
		}

		if (other_node->left_ != nullptr) {
			cur_node->left_ = new Node;
			cur_node->value_ = other_node->left_->value_;
			copy_node(cur_node->left_, other_node->left_);
		}
		if (other_node->right_ != nullptr) {
			cur_node->right_ = new Node;
			cur_node->value_ = other_node->right_->value_;
			copy_node(cur_node->right_, other_node->right_);
		}
	}
} */