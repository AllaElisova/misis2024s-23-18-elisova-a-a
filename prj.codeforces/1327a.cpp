#include <iostream>

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		long long int number = 0;
		long long int counter = 0;
		std::cin >> number >> counter;

		if (counter*counter > number) {
			std::cout << "NO" << std::endl;
		}

		else if ((number % 2) != (counter % 2)) {
			std::cout << "NO" << std::endl;
		}
			
		else {
			std::cout << "YES" << std::endl;
		}
	}	
}