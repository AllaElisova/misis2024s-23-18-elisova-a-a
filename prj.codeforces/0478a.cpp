#include <iostream>

int main() {
	int a = 0;
	int summa = 0;
	for (int i = 0; i < 5; ++i) {
		std::cin >> a;
		summa += a;
	}

	if (summa % 5 != 0) {
		std::cout << "-1" << std::endl;
	}

	else if (summa == 0) {
		std::cout << "-1" << std::endl;
	}

	else {
		std::cout << summa / 5 << std::endl;
	}
}