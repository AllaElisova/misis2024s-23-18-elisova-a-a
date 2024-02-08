#include <iostream>
#include <stack/stack.hpp>
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
}