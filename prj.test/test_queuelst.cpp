#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <complex/complex.hpp>
#include <queuelst/queuelst.hpp>
#include "doctest.h"


TEST_CASE("copy ctor") {
	QueueLst q;
	CHECK_EQ(q.IsEmpty(), true);
	Complex z(1, 2);
	q.Push(z);
	QueueLst u(q);
	CHECK_EQ(u.Top(), z);
	CHECK_EQ(u.End(), z);
	u.Push(Complex(2, 3));
	u.Push(Complex(3, 4));
	CHECK_EQ(u.Top(), Complex(1, 2));
	CHECK_EQ(u.End(), Complex(3, 4));
}

TEST_CASE("eq operator") {
	QueueLst q;
	Complex z(8, 9);
	q.Push(z);
	QueueLst u = q;
	CHECK_EQ(u.Top(), z);
	CHECK_EQ(u.End(), z);
}

TEST_CASE("push") {
	QueueLst q;
	Complex z1(1, 2);
	Complex z4(4, 5);
	q.Push(Complex(1, 2));
	q.Push(Complex(2, 3));
	q.Push(Complex(3, 4));
	q.Push(Complex(4, 5));
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(q.End(), z4);
}

TEST_CASE("pop"){
	QueueLst q;
	Complex z1(1, 2);
	Complex z2(2, 3);
	Complex z3(3, 4);
	q.Push(Complex(1, 2));
	q.Push(Complex(2, 3));
	q.Push(Complex(3, 4));
	q.Push(Complex(4, 5));
	q.Pop();
	CHECK_EQ(q.Top(), z2);
	q.Pop();
	CHECK_EQ(q.Top(), z3);
}

