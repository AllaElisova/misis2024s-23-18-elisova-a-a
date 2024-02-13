#include <iostream>
#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

int main() {
	StackLst a;
	a.Push(Complex(1, 2));
	std::cout << a.Top() << std::endl;
}