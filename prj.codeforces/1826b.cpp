#include <iostream>
#include <vector>
#include <algorithm>

int NOD(int a, int b) {
	if ((a == 0) || (b == 0)) {
		return std::max(a, b);
	}

	else {
		if (a < b) {
			std::swap(a, b);
		}
		while (a % b != 0) {
			a = a % b;
			std::swap(a, b);
		}
		return b;
	}
}

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int number = 0;
		std::cin >> number;
		std::vector <int> v(number);

		for (int j = 0; j < number; ++j) {
			int a = 0;
			std::cin >> a;
			v.at(j) = a;
		}

		int answer = 0;

		for (int j = 0; j < number; ++j) {
			answer = NOD(answer, std::abs(v.at(j) - v.at(number - j - 1)));
		}

		std::cout << answer << std::endl;
	}
}