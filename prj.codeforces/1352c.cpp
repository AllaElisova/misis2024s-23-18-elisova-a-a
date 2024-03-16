// not finished

#include <iostream>

bool s(int number, int del) {
	if (number % del == 0) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {
		int ind = 0;
		int del = 0;
		std::cin >> del >> ind;

		
		int answer = (ind - 1) / (del - 1) + ind;


		std::cout << answer << std::endl;
	}
}