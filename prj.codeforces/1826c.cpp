#include <iostream>
#include <cmath>

int min_del(int ppl) {
	int res = 1;
	for (int i = 2; i < std::sqrt(ppl) + 1; ++i) {
		if (ppl % i == 0) {
			res = i;
			break;
		}
	}

	if (res == 1) {
		return ppl;
	}
	else {
		return res;
	}
}

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int people, variants;
		std::cin >> people >> variants;

		if (people == 1) {
			std::cout << "YES" << std::endl;
		}
		else if (min_del(people) <= variants) {
			std::cout << "NO" << std::endl;
		}
		else {
			std::cout << "YES" << std::endl;
		}
	}
}