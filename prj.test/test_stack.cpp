#include <iostream>
#include <stack/stack.hpp>
#include <complex/complex.hpp>

int main() {
	StackArr a;
	a.Push({1,2});
	StackArr b{ a };
	std::cout << (b.Top()) << std::endl;
}