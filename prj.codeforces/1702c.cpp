// not finished

#include <iostream>
#include <vector>
#include <utility>

int main() {
	int times = 0;
	char a;
	std::cin >> times >> a;

	for (int i = 0; i < times; ++i) {
		int stations = 0;
		int requests = 0;
		std::vector <std::pair<int, int>> v(1000000000);
		std::cin >> stations >> requests;

		for (int j = 1; j <= stations; ++j) {
			int station = 0;
			std::cin >> station;

			if ((&v.at(station))->first == 0) {
				(&v.at(station))->first = j;
			}
			else {
				(&v.at(station))->second = j;
			}
		}

		for (int j = 0; j < requests; ++j) {
			int a = 0;
			int b = 0;
			std::cin >> a >> b;

			if (((&v.at(a))->first > 0) && ((&v.at(b))->first > 0)) {
				if ((&v.at(a))->first <= ((&v.at(b))->second)){
					std::cout << "YES" << std::endl;
				}
				else {
					std::cout << "NO" << std::endl;
				}
			}
			else {
				std::cout << "NO" << std::endl;
			}
		}
	}
}