#include <iostream>
#include <vector>


int solve(int num) {;
	while (num < 1000000) {
		bool ok = true;
		int copy = num;

		while (copy > 0) {
			if (copy % 3 == 2) {
				ok = false;
				break;
			}
			copy /= 3;
		}

		if (ok) {
			break;
		}
		else {
			++num;
		}
	}
	return num;
}

int main() {
	int quantity = 0;
	std::cin >> quantity;

	std::vector <int> answer(quantity);

	for (int i = 0; i < quantity; ++i) {
		int number = 0;
		std::cin >> number;
		answer.at(i) = solve(number);
	}

	for (int i = 0; i < quantity; ++i) {
		std::cout << answer.at(i) << "\n";
	}
}