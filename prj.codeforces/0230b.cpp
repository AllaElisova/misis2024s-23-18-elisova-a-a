// превышено ограничение по времени на тесте 7

#include <iostream>
#include <unordered_set>
#include <cmath>

std::unordered_set<long long int> prime_squares(0);

bool IsPrime(long long int num) {
	for (long long int i = 2; i < std::sqrt(num) + 1; ++i) {
		if (num % i == 0) {
			return false;
			break;
		}
	}
	return true;
}

void Fill() {
	prime_squares.insert(4);
	for (long long int i = 3; i <= 1000000; ++i) {
		if (IsPrime(i)) {
			prime_squares.insert(i * i);
		}
	}
}

int main() {
	int quantity = 0;
	std::cin >> quantity;

	Fill();

	for (int i = 0; i < quantity; ++i) {
		long long int number = 0;
		std::cin >> number;

		if (prime_squares.count(number) > 0) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
}

