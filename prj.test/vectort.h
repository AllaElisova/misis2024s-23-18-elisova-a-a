#pragma once

#ifndef VECTORT_H
#define VECTORT_H

#include <vector>
#include <complex/complex.hpp>
#include <rational/rational.hpp>

template <class T>

std::vector<T> make_vector() {

	std::vector<T> v(0);

	if constexpr (std::is_same_v<T, std::string>) {
		//if (typeid(T) == typeid(std::string)) {
		v.push_back("abc");
		v.push_back("///");
		v.push_back("...");
		v.push_back("denis gorin");
		v.push_back("asya lizander");
		v.push_back("vasya shvartz");
		v.push_back("polevoy");
	}
	else if constexpr (std::is_same_v<T, Complex>) {
		Complex z1(1, 2);
		Complex z2(3, 4);
		Complex z3(5, 6);
		Complex z4(7, 8);
		Complex z5(9, 10);
		Complex z6(11, 12);
		Complex z7(13, 14);
		v.push_back(z1);
		v.push_back(z2);
		v.push_back(z3);
		v.push_back(z4);
		v.push_back(z5);
		v.push_back(z6);
		v.push_back(z7);
	}
	else if constexpr (std::is_same_v<T, Rational>) {
		Rational r1(1, 2);
		Rational r2(2, 3);
		Rational r3(3, 4);
		Rational r4(4, 5);
		v.push_back(r1);
		v.push_back(r2);
		v.push_back(r3);
		v.push_back(r4);
	}
	else {
		for (int i = 0; i < 100; ++i) {
			v.push_back(T(i));
		}
	}
	return v;
}

#endif