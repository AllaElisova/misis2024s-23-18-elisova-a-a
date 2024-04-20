#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstdint>
#include <vector>
#include <string>
#include <complex/complex.hpp>
#include <rational/rational.hpp>
#include <stackarrt/stackarrt.hpp>
#include "doctest.h"
#include "vectort.h"

TEST_CASE_TEMPLATE("stupid push", T, int, double, std::string, Complex, Rational) {
    std::vector<T> vec = make_vector<T>();
    StackArrT<T> sa;

    for (T t : vec) {
        sa.Push(t);
    }

    for (int i = 1; i <= vec.size(); ++i) {
        CHECK_EQ(sa.Top(), vec.at(vec.size() - i));
        sa.Pop();
    }
}

