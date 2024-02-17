#include <iostream>
#include <array>
#include <string>

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int quantity = 0;
		std::cin >> quantity;

		std::array <int, 101> arr{ 0 };

		int sum_chet = 0;
		int sum_nechet = 0;

		for (int j = 0; j < quantity; ++j) {
			int number = 0;
			std::cin >> number;
			arr[number] += 1;

			if (number % 2 == 0) {
				sum_chet++;
			}
			else {
				sum_nechet++;
			}
		}

		if (sum_chet % 2 == 0) {
			std::cout << "YES" << std::endl;
		}

		else {
			std::string answer = "NO";
			int last = -1000;

			for (int j = 1; j < 101; ++j) {
				if (arr[j] > 0) {
					if (std::abs(j - last) == 1) {
						answer = "YES";
						break;
					}

					else {
						last = j;
					}
				}
			}

			std::cout << answer << std::endl;
		}
	}
}