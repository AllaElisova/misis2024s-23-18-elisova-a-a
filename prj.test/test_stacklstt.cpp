
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stacklstt/stacklstt.hpp>
#include <complex/complex.hpp>
#include "doctest.h"

Complex z1(1, 2);
Complex z2(3, 4);
Complex z3(5, 6);
Complex z4(7, 8);
Complex z5(9, 10);
Complex z6(11, 12);
Complex z7(13, 14);

TEST_CASE("default ctor") {
  StackLstT s;
  CHECK_EQ(s.IsEmpty(), true);

  StackLstT q = s;
  CHECK_EQ(q.IsEmpty(), true);
  q.Push(Complex(1, 2));
  CHECK_EQ(q.Top(), Complex(1, 2));
}

TEST_CASE("copy ctor") {
  StackLstT ss;
  ss.Push(z1);
  ss.Push(z2);
  ss.Push(z3);

  StackLstT s(ss);

  CHECK_EQ(z3, s.Top());
  CHECK_EQ(z3, ss.Top());

  CHECK_EQ(s.IsEmpty(), false);

  s.Pop();
  CHECK_EQ(z2, s.Top());
  s.Pop();
  CHECK_EQ(z1, s.Top());

  CHECK_EQ(z3, ss.Top());
}

TEST_CASE("eq operator") {
  StackLstT ss;
  CHECK_THROWS(ss.Top());
  ss.Push(z1);
  ss.Push(z2);
  ss.Push(z3);
  StackLstT s = ss;

  CHECK_EQ(z3, s.Top());
  s.Pop();
  s.Pop();
  s.Pop();
  CHECK_THROWS(s.Top());
  CHECK_EQ(ss.Top(), z3);

  StackLstT q;
  q = s;
  CHECK_EQ(s.IsEmpty(), true);
}

TEST_CASE("clear") {
  StackLstT s;
  s.Push(Complex(7, 8));
  s.Push(Complex(9, 0));
  s.Clear();

  CHECK_EQ(s.IsEmpty(), true);
  s.Pop();
  CHECK_EQ(s.IsEmpty(), true);
}

TEST_CASE("move semantics") {
  StackLstT q;
  q.Push(z4);
  q.Push(z5);
  q.Push(z6);
  StackLstT&& h = std::move(q);
  StackLstT s(h);
  CHECK_EQ(s.Top(), z6);
  CHECK_EQ(h.IsEmpty(), false);
  CHECK_EQ(h.Top(), z6);
  s.Pop();
  CHECK_EQ(s.Top(), z5);

  StackLstT t;
  t.Push(z1);
  t = h;
  CHECK_EQ(t.Top(), z6);
  h.Push(z2);
  h.Push(z3);
  CHECK_EQ(t.Top(), z6);
  h.Clear();
  CHECK_EQ(t.Top(), z6);
}