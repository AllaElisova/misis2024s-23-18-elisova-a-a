#include <iostream>
#include <unordered_set>

std::unordered_set<long long int> cubes (0);

void fill() {
	for (long long int i = 1; i * i * i <= 1000000000000; ++i) {
		cubes.insert(i * i * i);
	}
}

int main() {
	int times = 0;
	std::cin >> times;
	
	fill();

	for (int i = 0; i < times; ++i) {
		long long int number = 0;
		std::cin >> number;

		bool flag = true;
		for (long long i = 1; i * i * i <= number; ++i) {
			if (cubes.count(number - i * i * i) > 0) {
				std::cout << "YES" << std::endl;
				flag = false;
				break;
			}
		}

		if (flag) {
			std::cout << "NO" << std::endl;
		}
	}
}