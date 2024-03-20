#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <queuelstpr/queuelstpr.hpp>
#include "doctest.h"

TEST_CASE("ctor") {
	QueueLstPr q = { 1.1f };
	CHECK_EQ(q.Top(), 1.1f);
	CHECK_EQ(q.IsEmpty(), false);
	QueueLstPr t(q);
	CHECK_EQ(t.Top(), 1.1f);
}

TEST_CASE("push/pop 1") {
	QueueLstPr q = { 1.1f };
	q.Push(1.2f);
	CHECK_EQ(q.Top(), 1.1f);
	q.Push(1.3f);
	q.Push(1.0f);
	CHECK_EQ(q.Top(), 1.0f);
	q.Push(0.5f);
	CHECK_EQ(q.Top(), 0.5f);
	q.Push(0.6f);
	q.Push(0.7f);
	CHECK_EQ(q.Top(), 0.5f);
	q.Pop();
	CHECK_EQ(q.Top(), 0.6f);
	q.Pop();
	CHECK_EQ(q.Top(), 0.7f);
}

TEST_CASE("push/pop 2") {
	QueueLstPr q = { 5.0f };
	q.Push(2.0f);
	q.Push(8.0f);
	CHECK_EQ(q.Top(), 2.0f);
	q.Push(1.0f);
	q.Push(4.0f);
	q.Push(3.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 2.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 3.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 4.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 5.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 8.0f);
	q.Pop();
	CHECK_EQ(q.IsEmpty(), true);
}

TEST_CASE("push/pop 3") {
	QueueLstPr q;
	q.Push(5.0f);
	CHECK_EQ(q.Top(), 5.0f);
	q.Push(10.0f);
	q.Push(9.0f);
	q.Push(11.0f);
	q.Push(6.0f);
	CHECK_EQ(q.Top(), 5.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 6.0f);
	q.Push(10.5f);
	q.Push(12.0f);
	q.Push(7.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 7.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 9.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 10.0f);
	q.Pop();
	CHECK_EQ(q.Top(), 10.5f);
	q.Pop();
	q.Pop();
	CHECK_EQ(q.Top(), 12.0f);
	q.Push(12.5f);
	q.Pop();
	CHECK_EQ(q.Top(), 12.5f);
	q.Pop();
	q.Pop();
	q.Pop();
	CHECK_THROWS(q.Top());
}

TEST_CASE("clear") {
	QueueLstPr q = { 1.0f, 2.0f, 3.0f };
	CHECK_EQ(q.Top(), 1.0f);
	q.Clear();
	CHECK_EQ(q.IsEmpty(), true);
}

TEST_CASE("copy ctor") {
	QueueLstPr q = {1.0f, 2.0f, 3.0f};
	QueueLstPr t(q);
	CHECK_EQ(t.Top(), 1.0f);
	t.Pop();
	t.Pop();
	CHECK_EQ(t.Top(), 3.0f);
}

TEST_CASE("eq operator") {
	QueueLstPr q = { 1.0f, 2.0f, 3.0f };
	QueueLstPr t = { 4.0f, 5.0f, 6.0f, 7.0f };
	t = q;
	CHECK_EQ(t.Top(), 1.0f);
	t.Pop();
	t.Pop();
	t.Pop();
	CHECK_EQ(t.IsEmpty(), true);
}