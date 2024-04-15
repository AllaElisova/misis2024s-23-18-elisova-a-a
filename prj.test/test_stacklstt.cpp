#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <stacklstt/stacklstt.hpp>
#include <complex/complex.hpp>
#include <rational/rational.hpp>
#include "doctest.h"
#include "vectort.h"

Complex z1(1, 2);
Complex z2(3, 4);
Complex z3(5, 6);
Complex z4(7, 8);
Complex z5(9, 10);
Complex z6(11, 12);
Complex z7(13, 14);

TEST_CASE_TEMPLATE("stupid push", T, int, double, std::string, Complex) {
  std::vector<T> vec = make_vector<T>();
  StackLstT<T> sl;
  for (T t : vec) {
    sl.Push(t);
  }
  for (int i = 1; i <= vec.size(); ++i) {
    CHECK_EQ(sl.Top(), vec[vec.size() - i]);
    sl.Pop();
  }
}

/*TEST_CASE("default ctor") {
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
} */
/*
TEST_CASE("template test 1") {
  float num{ 9.0f };
  StackLstT <float> s;
  s.Push(num);
  CHECK_EQ(s.IsEmpty(), false);
  s.Pop();
  CHECK_EQ(s.IsEmpty(), true);
}

Complex c{ 2.0, 2.0 };
Rational r{ 9, 8 };
int32_t i{ 9 };
double d{ 9.8 };

TEST_CASE_TEMPLATE("help", T, Complex, Rational, int32_t, double){
  StackLstT<T> sc;
  sc.Push(c);
  CHECK_EQ(sc.Top(), Complex(2.0, 2.0));
  sc.Push(z1);
  sc.Push(z2);
  CHECK_EQ(sc.Top(), z2);

  StackLstT <T> sr;
  sr.Push(r);
  CHECK_EQ(sr.IsEmpty(), false);
  CHECK_EQ(sr.Top(), Rational(9, 8));
  sr.Pop();
  CHECK_EQ(sr.IsEmpty(), true);
  sr.Pop();
  sr.Pop();
  sr.Pop();
  CHECK_EQ(sr.IsEmpty(), true);

  StackLstT <T> si;
  si.Push(i);
  CHECK_EQ(si.Top(), 9);

  StackLstT <T> sd;
  sd.Push(d);
  CHECK_EQ(sd.IsEmpty(), false);
  sd.Push(5.6);
  sd.Push(6.7);
  sd.Push(7.8);
  sd.Clear();
  CHECK_EQ(sd.IsEmpty(), true);

} */

// в начале дефайн в котором можно перечислить типы
// можно сделать хэдер с выносом специализаций шаблона и цеплть его к тестам