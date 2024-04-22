/*#pragma once

#ifndef QUEUELSTPRT_QUEUELSTPRT_HPP
#define QUEUELSTPRT_QUEUELSTPRT_HPP

#include <stdexcept>
#include <initializer_list>
#include <memory>

template <typename T>
class QueueLstPrT {
public:
	QueueLstPrT() = default;
	QueueLstPrT(const QueueLstPrT& other);
	QueueLstPrT(QueueLstPrT&& other) noexcept;
	QueueLstPrT(const std::initializer_list<T>& list);

	QueueLstPrT& operator= (const QueueLstPrT& other);
	QueueLstPrT& operator= (QueueLstPrT&& other) noexcept;
	QueueLstPrT& operator= (const std::initializer_list<T> list);

	bool IsEmpty() const noexcept;

	void Push(const T& elem);
	void Pop() noexcept;

	T& Top();
	const T& Top() const;

	void Clear() noexcept;

	~QueueLstPrT();

private:
	//template <typename T>
	struct Node {
		Node() = default;
		Node(const Node& other);
		Node(const Node* other);

		//template <typename T>
		Node& operator= (const Node& other);

		T value_;
		Node* left_ = nullptr;
		Node* right_ = nullptr;
		int32_t count_ = 0;

	};


	void copy_node(Node* cur_node, const Node* other_node) noexcept;

	void Clear(Node* node) noexcept;

	Node* root_ = nullptr;
};

template <typename T>
using QuPrNode = typename QueueLstPrT<T>::Node;

//template <typename T>
QuPrNode& QuPrNode::operator=(typename const QuPrNode& other) {
	value_ = other.value_;
	count_ = other.count_;
	return *this;
}

template <typename T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT& other) {
	if (other.IsEmpty() == false) {
		root_ = new Node<T>(other.root_);
		copy_node(root_, other.root_);
	}
}

template <typename T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT&& other) noexcept {
	std::swap(root_, other.root_);
	other.root_ = nullptr;
}

template <typename T>
QueueLstPrT<T>::QueueLstPrT(const std::initializer_list<T>& list) {
	for (T elem : list) {
		Push(elem);
	}
}

template <typename T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT& other) {
	if (this != &other) {
		if (other.IsEmpty()) {
			(*this).Clear();
		}
		else {
			(*this).Clear();
			root_ = new Node(other.root_);
			copy_node(root_, other.root_);
		}
	}

	return *this;
}

template <typename T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(QueueLstPrT&& other) noexcept {
	std::swap(root_, other.root_);
	other.root_ = nullptr;

	return *this;
}

template <typename T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const std::initializer_list<T> list) {
	Clear();
	for (T elem : list) {
		Push(elem);
	}

	return *this;
}

template <typename T>
bool QueueLstPrT<T>::IsEmpty() const noexcept {
	return (root_ == nullptr);
}

template <typename T>
void QueueLstPrT<T>::Push(const T& elem) {
	if (IsEmpty()) {
		root_ = new Node<T>;
		root_->value_ = elem;
	}

	else {
		Node<T>* new_elem = new Node<T>;
		new_elem->value_ = elem;

		Node<T>* temp = root_;
		Node<T>* prev_temp = nullptr;

		while (temp != nullptr) {

			prev_temp = temp;

			if (elem < temp->value_) {
				temp = temp->left_;
			}

			else if (elem > temp->value_) {
				temp = temp->right_;
			}

			else {
				++(temp->count_);
				break;
			}
		}

		if (elem < prev_temp->value_) {
			prev_temp->left_ = new_elem;
		}

		else if (elem > prev_temp->value_) {
			prev_temp->right_ = new_elem;
		}

	}
}

template <typename T>
void QueueLstPrT<T>::Pop() noexcept {
	if ((*this).IsEmpty() == false) {

		Node<T>* temp = root_;
		Node<T>* prev_temp = nullptr;

		while (temp != nullptr) {
			if (temp->left_ != nullptr) {  
				prev_temp = temp;
				temp = temp->left_;
			}

			else if (temp->count_ != 0) {
				--(temp->count_);
				break;
			}

			else if (temp->right_ != nullptr) {  

				if (temp == root_) {   
					root_ = temp->right_;
					delete (temp);
					temp = nullptr;
				}

				else if (prev_temp->left_ == temp) {  
					prev_temp->left_ = temp->right_;
				}
				break;
			}

			else {  
				if (prev_temp == nullptr) {  
					Clear();
					break;
				}

				else if (prev_temp->left_ == temp) {
					prev_temp->left_ = nullptr;
				}
				else if (prev_temp->right_ == temp) {
					prev_temp->right_ = nullptr;
				}
				delete (temp);
				temp = nullptr;
			}
		}
	}
}

template <typename T>
T& QueueLstPrT<T>::Top() {
	if (IsEmpty()) {
		throw std::logic_error("top of empty queue");
	}

	else {
		Node<T>* temp = root_;

		while (temp != nullptr) {
			if (temp->left_ != nullptr) {
				temp = temp->left_;
			}

			else if (temp->count_ != 0) {
				return (temp->value_);
			}

			else {
				return (temp->value_);
			}
		}
	}
}

template <typename T>
const T& QueueLstPrT<T>::Top() const {
	if (IsEmpty()) {
		throw std::logic_error("top of empty queue");
	}

	Node<T>* temp = root_;

	while (temp != nullptr) {
		if (temp->left_ != nullptr) {
			temp = temp->left_;
		}

		else if (temp->count_ != 0) {
			return (temp->value_);
		}

		else {
			return (temp->value_);
		}
	}
}

template <typename T>
void QueueLstPrT<T>::Clear() noexcept {
	Clear(root_);
	root_ = nullptr;
}

template <typename T>
void QueueLstPrT<T>::Clear(Node* node) noexcept {
	if (node != nullptr) {

		Clear(node->left_);
		Clear(node->right_); 
		delete node;
		node = nullptr;
	}
}

template <typename T>
QueueLstPrT<T>::~QueueLstPrT() {
	Clear();
}

template <typename T>
QueueLstPrT<T>::Node::Node(const Node& other) {
	value_ = other.value_;
	count_ = other.count_;
}

template <typename T>
QueueLstPrT<T>::Node::Node(const Node* other) {
	value_ = other->value_;
	count_ = other->count_;
}

/*template <typename T>
QuPrNode& QuPrNode::operator= (const QuPrNode& other) {
	value_ = other.value_;
	count_ = other.count_;
	return *this;
} */
 /*
template <typename T>
void QueueLstPrT<T>::copy_node(Node* cur_node, const Node* other_node) noexcept {
	if (other_node != nullptr) {

		if (cur_node == nullptr) {
			cur_node = new Node;
			*cur_node = *other_node;
		}

		if (other_node->left_ != nullptr) {
			cur_node->left_ = new Node;
			*(cur_node->left_) = *(other_node->left_);
			copy_node(cur_node->left_, other_node->left_);
		}
		if (other_node->right_ != nullptr) {
			cur_node->right_ = new Node;
			*(cur_node->right_) = *(other_node->right_);
			copy_node(cur_node->right_, other_node->right_);
		}
	}
}

#endif 

 */