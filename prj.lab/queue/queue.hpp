#pragma once

#ifndef	QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

#include <initializer_list>

class Queue {
public:
	Queue() = default;
	Queue(const Queue& other);
	Queue(const std::initializer_list<>& list);

	Queue& operator=(const Queue& other);

	void Push();
	void Pop();
	void Clear();

	~Queue() = default;
};

#endif