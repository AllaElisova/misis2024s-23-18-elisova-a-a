#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <complex/complex.hpp>
#include <queuearr/queuearr.hpp>
#include "doctest.h"


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

TEST_CASE("ctor") {
	QueueArr q;
	QueueArr r(q);
	CHECK_EQ(q.IsEmpty(), true);
	CHECK_EQ(r.IsEmpty(), true);
	CHECK_THROWS(r.Top());
}

TEST_CASE("init list ctor") {

	QueueArr q{ z1, z2 };

	CHECK_EQ(q.IsEmpty(), false);
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(q.End(), z2);
}

TEST_CASE("eq operator") {

	QueueArr q{z1};
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
	CHECK_THROWS(empty1.Top());

	QueueArr t = { z1, z2, z3 };
	CHECK_EQ(t.IsEmpty(), false);
	CHECK_EQ(t.Top(), z1);
	CHECK_EQ(t.End(), z3);

	QueueArr TEST;
	TEST.Push(z1);
	TEST = { z2, z3 };

	CHECK_EQ(TEST.Top(), z2);
	CHECK_EQ(TEST.End(), z3);
	CHECK_EQ(TEST.End(), z3);
	CHECK_EQ(TEST.End(), z3);
}

TEST_CASE("push") {

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

	QueueArr w;
	w.Push(Complex(1, 2));
	w.Push(Complex(2, 3));
	w.Push(Complex(3, 4));
	w.Push(Complex(4, 5));
	w.Push(Complex(1, 2));
	w.Push(Complex(2, 3));
	w.Push(Complex(3, 4));
	w.Push(Complex(4, 5));
	w.Push(Complex(1, 2));
	w.Push(Complex(2, 3));
	w.Push(Complex(3, 4));
	w.Push(Complex(4, 5));
	w.Push(Complex(1, 2));
	w.Push(Complex(2, 3));
	w.Push(Complex(3, 4));
	w.Push(Complex(4, 5));
	w.Push(Complex(1, 2));
	w.Push(Complex(2, 3));
	w.Push(Complex(3, 4));
	w.Push(Complex(4, 5));
	w.Push(Complex(1, 2));
	w.Push(Complex(2, 3));
	w.Push(Complex(3, 4));
	w.Push(Complex(4, 5));

	CHECK_EQ(w.Top(), z1);
	CHECK_EQ(w.End(), z4);
	w.Pop();
	CHECK_EQ(w.Top(), z2);
	w.Pop();
	CHECK_EQ(w.Top(), z3); 
}

TEST_CASE("pop") {

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

	QueueArr q{ z1, z2, z3, z4 };
	q.Clear();
	CHECK_EQ(q.IsEmpty(), true);
	q.Pop();
	q.Pop();
	CHECK_THROWS(q.Top());
	CHECK_THROWS(q.End());
}

Complex c1(1, 2);
Complex c2(2, 3);
Complex c3(3, 4);

TEST_CASE("generic check") {
	QueueArr qa;
	qa.Push(c1);
	qa.Push(c2);
	qa.Push(c3);
	CHECK_EQ(c1, qa.Top());
	qa.Pop();
	CHECK_EQ(c2, qa.Top());
	qa.Pop();
	CHECK_EQ(c3, qa.Top());
	qa.Pop();
	CHECK(qa.IsEmpty());
}

TEST_CASE("init list") {
	QueueArr qa{ c1, c2, c3 };
	CHECK_EQ(c1, qa.Top());
	qa.Pop();
	CHECK_EQ(c2, qa.Top());
	qa.Pop();
	CHECK_EQ(c3, qa.Top());
	qa.Pop();
	CHECK(qa.IsEmpty());
}

TEST_CASE("COPY_CTOR") {
	QueueArr qa{ c1, c2, c3 };
	QueueArr qac(qa);
	CHECK_EQ(c1, qac.Top());
	qac.Pop();
	CHECK_EQ(c2, qac.Top());
	qac.Pop();
	CHECK_EQ(c3, qac.Top());
	qac.Pop();
	CHECK(qac.IsEmpty());
}

TEST_CASE("operator eq") {
	QueueArr qa1{ c1 };
	QueueArr qa2{ c1, c2 };
	QueueArr qa3{ c1, c2, c3 };
	QueueArr qa2_1{ c1, c2 };
	QueueArr qa2_2{ c1, c2 };
	QueueArr qa2_3{ c1, c2 };
	
	qa2_1 = qa1;
	qa2_2 = qa2;
	qa2_3 = qa3;

	CHECK_EQ(c1, qa2_1.Top());
	qa2_1.Pop();
	CHECK(qa2_1.IsEmpty());

	CHECK_EQ(c1, qa2_2.Top());
	qa2_2.Pop();
	CHECK_EQ(c2, qa2_2.Top());
	qa2_2.Pop();
	CHECK(qa2_2.IsEmpty());

	CHECK_EQ(c1, qa2_3.Top());
	qa2_3.Pop();
	CHECK_EQ(c2, qa2_3.Top());
	qa2_3.Pop();
	CHECK_EQ(c3, qa2_3.Top());
	qa2_3.Pop();
	CHECK(qa2_3.IsEmpty());
}

TEST_CASE("CLEAR CHECK") {
	QueueArr qa;
	CHECK(qa.IsEmpty());
	qa.Push(c1);
	CHECK_FALSE(qa.IsEmpty());
	qa.Clear();
	CHECK(qa.IsEmpty());
}

TEST_CASE("TOP THROW") {
	QueueArr qa{ c1 };
	CHECK_NOTHROW((void)qa.Top());
	qa.Pop();
	CHECK_THROWS((void)qa.Top());
}