#include <iostream>


int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int number = 0;
		int distance = 0;
		std::cin >> number >> distance;

		int last = -1000000000;
		int answer = 0;

		for (int j = 0; j < number; ++j) {
			char table;
			std::cin >> table;

			if (table == '0') {
				if (std::abs(j - last) > distance) {
					++answer;
					last = j;
				}
			}
			else if (table == '1'){
				if (std::abs(j - last) <= distance) {
					--answer;
				}
				last = j;
			}

		
		}

		
		std::cout << answer << "\n";
	}
}