/* #pragma once

#ifndef QUEUELSTPR_QUEUELSTPR_HPP
#define QUEUELSTPR_QUEUELSTPR_HPP

class QueueLstPr {
public:
	QueueLstPr() = default;
	QueueLstPr(const QueueLstPr& other);
	QueueLstPr(QueueLstPr&& other);

	QueueLstPr& operator= (const QueueLstPr& other);
	QueueLstPr& operator= (QueueLstPr&& other);

	void Push();
	void Pop() noexcept;

	int& Top();
	const int& Top() const;

	int& End();
	const int& End() const;

	void Clear() noexcept;

private:
	struct Node {
		int v;
		Node* next = nullptr;

	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif */