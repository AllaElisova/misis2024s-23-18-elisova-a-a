#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <complex/complex.hpp>
#include <queuearr/queuearr.hpp>
#include "doctest.h"

TEST_CASE("ctor") {
	QueueArr q;
	QueueArr r(q);
	CHECK_EQ(q.IsEmpty(), true);
	CHECK_EQ(r.IsEmpty(), true);
	CHECK_THROWS(r.Top());
}

TEST_CASE("init list ctor") {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	QueueArr q{ z1, z2 };

	CHECK_EQ(q.IsEmpty(), false);
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(q.End(), z2);
}

TEST_CASE("eq operator") {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	Complex z3 = Complex(3, 4);

	QueueArr q{ z1 };
	QueueArr r;
	r = q;
	CHECK_EQ(q.IsEmpty(), false);
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(r.Top(), z1);
	CHECK_EQ(r.End(), z1);

	QueueArr empty1;
	QueueArr empty2;
	empty1 = empty2;
	CHECK_EQ(empty1.IsEmpty(), true);

	QueueArr t = { z1, z2, z3 };
	CHECK_EQ(t.IsEmpty(), false);
	CHECK_EQ(t.Top(), z1);
	CHECK_EQ(t.End(), z3);

	QueueArr TEST;
	TEST.Push(z1);
	TEST = { z2, z3 };

	CHECK_EQ(TEST.Top(), z2);
	CHECK_EQ(TEST.End(), z3);
}

TEST_CASE("push") {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	Complex z3 = Complex(3, 4);
	Complex z4 = Complex(4, 5);
	Complex z5 = Complex(5, 6);
	Complex z6 = Complex(6, 7);
	Complex z7 = Complex(7, 8);
	Complex z8 = Complex(8, 9);
	Complex z9 = Complex(9, 10);

	QueueArr q;
	q.Push(z1);
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(q.End(), z1);
	q.Push(z2);
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(q.End(), z2);
	q.Push(z3);
	q.Push(z4);
	q.Push(z5);
	CHECK_EQ(q.End(), z5);
	q.Push(z6);
	q.Push(z7);
	q.Push(z8);
	q.Push(z9);
	CHECK_EQ(q.End(), z9);
}

TEST_CASE("pop") {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	Complex z3 = Complex(3, 4);
	Complex z4 = Complex(4, 5);
	Complex z5 = Complex(5, 6);
	Complex z6 = Complex(6, 7);
	Complex z7 = Complex(7, 8);
	Complex z8 = Complex(8, 9);
	Complex z9 = Complex(9, 10);
	Complex z10 = Complex(10, 11);
	Complex z11 = Complex(11, 12);
	Complex z12 = Complex(12, 13);
	Complex z13 = Complex(13, 14);
	Complex z14 = Complex(14, 15);
	Complex z15 = Complex(15, 16);

	QueueArr q;
	q.Push(z1);
	q.Push(z2);
	q.Push(z3);
	q.Pop();
	CHECK_EQ(q.Top(), z2);
	CHECK_EQ(q.End(), z3);
	q.Push(z4);
	q.Push(z5);
	q.Push(z6);
	q.Push(z7);
	q.Push(z8);
	q.Pop();
	q.Push(z9);
	q.Push(z10);
	q.Push(z11);
	CHECK_EQ(q.End(), z11);
	q.Pop();
	q.Pop();
	q.Push(z12);
	CHECK_EQ(q.End(), z12);
	q.Push(z13);
	q.Push(z14);
	q.Push(z15);
	CHECK_EQ(q.End(), z15);
}

TEST_CASE("clear") {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	Complex z3 = Complex(3, 4);
	Complex z4 = Complex(4, 5);
	QueueArr q{ z1, z2, z3, z4 };
	q.Clear();
	CHECK_EQ(q.IsEmpty(), true);
	q.Pop();
	q.Pop();
	CHECK_THROWS(q.Top());
	CHECK_THROWS(q.End());
}

TEST_CASE("moving ctor") {

}