#include <iostream>
#include <vector>

int main() {
	int times = 0;
	std::cin >> times;

	std::vector <int> angles (times);

	for (int i = 0; i < times; ++i) {
		int alpha = 0;
		std::cin >> alpha;
		int diff = 180 - alpha;
		angles[i] = diff;
	}

	for (int i = 0; i < times; ++i) {
		if (360 % angles[i] == 0) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}