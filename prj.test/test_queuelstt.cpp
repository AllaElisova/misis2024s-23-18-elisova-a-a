#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstdint>
#include <vector>
#include <string>
#include <complex/complex.hpp>
#include <rational/rational.hpp>
#include <queuelstt/queuelstt.hpp>
#include "doctest.h"
#include "vectort.h"

TEST_CASE_TEMPLATE("stupid push", T, int, double, std::string, Complex, Rational) {
    std::vector<T> vec = make_vector<T>();
    QueueLstT<T> ql;

    for (T t : vec) {
        ql.Push(t);
    }

    for (int i = 0; i < vec.size(); ++i) {
        CHECK_EQ(ql.Top(), vec[i]);
        ql.Pop();
    }
}

