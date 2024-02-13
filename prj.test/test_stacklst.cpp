/* #include <iostream>
#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

int main() {
	StackLst a;
	std::cout << a.IsEmpty() << std::endl;
	a.Push(Complex(1, 2));
	std::cout << a.Top() << std::endl;
	a.Push(Complex(3, 4));
	std::cout << a.Top() << std::endl;
} */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>
#include "doctest.h"
#include <fstream>

Complex z1(1, 2);
Complex z2(3, 4);
Complex z3(5, 6);

TEST_CASE("default ctor") {
	StackLst s;
  CHECK_EQ(s.IsEmpty(), true);
}

TEST_CASE("copy ctor") {
  StackLst ss;
  ss.Push(z1);
  ss.Push(z2);
  ss.Push(z3);

  StackLst s(ss);

  CHECK_EQ(z3, s.Top());
  s.Pop();
  CHECK_EQ(z2, s.Top());
  s.Pop();
  CHECK_EQ(z1, s.Top());

  CHECK_EQ(z3, ss.Top());
} 
