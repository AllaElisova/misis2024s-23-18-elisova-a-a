#pragma once

#ifndef QUEUELSTPR_QUEUELSTPR_HPP
#define QUEUELSTPR_QUEUELSTPR_HPP

#include <stdexcept>
#include <initializer_list>

class QueueLstPr {
public:
	 QueueLstPr() = default;
	 QueueLstPr(const QueueLstPr& other);
	 QueueLstPr(QueueLstPr&& other);
	 QueueLstPr(const std::initializer_list<float>& list);

	 QueueLstPr& operator= (const QueueLstPr& other);
	 QueueLstPr& operator= (QueueLstPr&& other);
	 QueueLstPr& operator= (const std::initializer_list<float> list);

	 bool IsEmpty() const noexcept;

	 void Push(const float& elem);
	 void Pop() noexcept;

	 float& Top();
	 const float& Top() const;

	 float& End();
	 const float& End() const;

	 void Clear() noexcept;

	 ~QueueLstPr();

private:
  struct Node {
		float value = 0;
		Node* prev_ = nullptr;
		Node* next_ = nullptr;
		size_t count = 0;

	};

	//void copy_node(Node* cur_node, const Node* other_node) noexcept;
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif 