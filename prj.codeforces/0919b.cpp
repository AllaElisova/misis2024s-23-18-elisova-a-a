#include <iostream>

int s(int number) {
	int summa = 0;
	while (number > 0) {
		summa += number % 10;
		number /= 10;
	}
	return summa;
}

int main() {
	int k = 0;
	std::cin >> k;

	int answer = 0;

	while (k > 0) {
		++answer;
		if (s(answer) == 10) {
			--k;
		}
	}
	std::cout << answer;
}