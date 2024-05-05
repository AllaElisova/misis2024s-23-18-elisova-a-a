#include <iostream>
#include <vector>

int main() {
	int quantity = 0;
	std::cin >> quantity;

	std::vector <int> v(quantity+1);
	int chet = 0;
	int nechet = 0;

	for (int i = 1; i <= quantity; ++i) {
		int number = 0;
		std::cin >> number;

		if (number % 2 == 1) {
			++nechet;
		}
		else if (number % 2 == 0) {
			++chet;
		}

		v.at(i) = number;
	}

	if (nechet > 1) {
		for (int i = 1; i <= quantity; ++i) {
			if (v.at(i) % 2 == 0) {
				std::cout << i;
				break;
			}
		}
	}

	else if (chet > 1) {
		for (int i = 1; i <= quantity; ++i) {
			if (v.at(i) % 2 == 1) {
				std::cout << i;
				break;
			}
		}
	}
}