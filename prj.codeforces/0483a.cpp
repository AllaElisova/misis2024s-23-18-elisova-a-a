#include <iostream>

int main() {
	long long int low = 0;
	long long int high = 0;
	std::cin >> low >> high;


	if (high - low < 2) {
		std::cout << -1;
	}
	else if (low % 2 == 0) {
		std::cout << low << ' ' << low + 1 << ' ' << low + 2;
	}
	else if (high - low > 2) {
		std::cout << low + 1 << ' ' << low + 2 << ' ' << low + 3;
	}
	else {
		std::cout << -1;
	}

}