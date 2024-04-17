#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int quantity = 0;
		std::cin >> quantity;

		std::vector <int> v(quantity);

		for (int j = 0; j < quantity; ++j) {
			int person = 0;
			std::cin >> person;
			v.at(j) = person;
		}
	
		bool flag = true;
		for (int cnt_liars = 0; cnt_liars <= quantity; ++cnt_liars) {
			int bad_guys = 0;
			for (int elem : v) {
				if (cnt_liars < elem) {
					++bad_guys;
				}
			}
			if (bad_guys == cnt_liars) {
				std::cout << cnt_liars << std::endl;
				flag = false;
				break;
			}
		}
		if (flag) {
			std::cout << "-1" << std::endl;
		}
	}
}