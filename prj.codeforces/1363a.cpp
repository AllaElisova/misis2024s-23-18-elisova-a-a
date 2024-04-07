#include <iostream>

int main() {
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {
		int length = 0;
		int quantity;
		std::cin >> length >> quantity;

		int chet = 0;
		int nechet = 0;

		for (int j = 0; j < length; ++j) {
			int elem = 0;
			std::cin >> elem;
			if (elem % 2 == 0) {
				++chet;
			}
			else {
				++nechet;
			}
		}

		bool flag = false;

		for (int j = 1; j <= nechet && j <= quantity; j+=2) {
			if ((quantity - j) <= chet) {
				flag = true;
			}
		}
		if (flag) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}