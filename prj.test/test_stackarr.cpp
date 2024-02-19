/* 

#include <iostream>
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>

int main() {
	StackArr a;
	a.Push(Complex(1,9));

	StackArr b{ a };
	std::cout << b.Top() << std::endl;

	a.Push(Complex(3, 4));
	std::cout << a.Top() << std::endl;
	std::cout << a.IsEmpty() << std::endl;

	a.Pop();
	std::cout << a.Top() << std::endl;

	StackArr c;
	c = b;
	std::cout << c.Top() << std::endl;

	c.Clear();
	std::cout << c.IsEmpty() << std::endl;
} */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>
#include "doctest.h"
#include <fstream>

Complex z1 (1, 2);
Complex z2 (3, 4);
Complex z3 (5, 6);

TEST_CASE("default ctor") {
  StackArr s;
  CHECK_THROWS(s.Top());
}

TEST_CASE("initializer list ctor") {
  StackArr s = { z1, z2, z3 };

  CHECK_EQ(z3, s.Top());
  s.Pop();
  CHECK_EQ(z2, s.Top());
  s.Pop();
  CHECK_EQ(z1, s.Top());
}

TEST_CASE("copy ctor") {
  StackArr ss = { z1, z2, z3 };
  /*StackArr ss;
  ss.Push(z1);
  ss.Push(z2);
  ss.Push(z3); */
  StackArr s (ss);

  CHECK_EQ(z3, s.Top());
  s.Pop();
  CHECK_EQ(z2, s.Top());
  s.Pop();
  CHECK_EQ(z1, s.Top());
  s.Pop();

  CHECK_EQ(z3, ss.Top());
}

TEST_CASE("eq operator") {
  StackArr ss = { z1, z2, z3 };
  StackArr s = ss;

  CHECK_EQ(z3, s.Top());
  s.Pop();
  CHECK_EQ(z2, s.Top());
  s.Pop();
  CHECK_EQ(z1, s.Top());

  CHECK_EQ(z3, ss.Top());
}

TEST_CASE("is empty") {
  StackArr s;
  CHECK_EQ(s.IsEmpty(), true);

  s.Push(z1);
  CHECK_EQ(z1, s.Top());
  CHECK_EQ(s.IsEmpty(), false);
  s.Pop();

  CHECK_EQ(s.IsEmpty(), true);
  CHECK_THROWS(s.Top());
} 
