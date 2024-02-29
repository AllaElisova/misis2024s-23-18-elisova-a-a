#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <complex/complex.hpp>
#include <queuearr/queuearr.hpp>
#include "doctest.h"

TEST_CASE("init list ctor") {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	QueueArr q{ z1, z2 };
	CHECK_EQ(q.IsEmpty(), false);
	CHECK_EQ(q.Top(), z1);
	CHECK_EQ(q.End(), z2);
}