/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstdint>
#include <vector>
#include <string>
#include <complex/complex.hpp>
#include <rational/rational.hpp>
#include <queuelstprt/queuelstprt.hpp>
#include "doctest.h"
#include "vectort.h"

TEST_CASE_TEMPLATE("stupid push", T, int, double, std::string, Complex, Rational) {
    std::vector<T> vec = make_vector<T>();
    QueueLstPrT<T> qlp;

    for (T t : vec) {
        qlp.Push(t);
    }

    for (int i = 0; i < vec.size(); ++i) {
        CHECK_EQ(qlp.Top(), vec.at(i));
        qlp.Pop();
    }
}
 */
