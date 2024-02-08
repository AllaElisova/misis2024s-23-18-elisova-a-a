// not finished

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int number = 0;
	std::cin >> number;

	std::vector <int> markets(number);

	int cost = 0;
	for (int i = 0; i < number; ++i) {
		std::cin >> cost;
		markets[i] = cost;
	}

	std::sort(markets.begin(), markets.end());

	int days = 0;
	std::cin >> days;

	for (int i = 0; i < days; ++i) {
		int answer = 0;

		int middle = number / 2;
		int left = 0;
		int right = number;

		int money = 0;
		std::cin >> money;

		while (left <= right) {
			if (money >= markets.at(middle)) {
				answer += middle - left;
				left = middle + 1;
				middle = (left + right) / 2;
			}

			else if (money < markets.at(middle)) {
				right = middle;
				middle = (left + right) / 2;
			}
		}
		std::cout << answer << std::endl;
	}
}
