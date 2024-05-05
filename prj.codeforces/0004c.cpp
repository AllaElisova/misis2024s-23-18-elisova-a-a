#include <iostream>
#include <string>
#include <vector>

int main() {
	int number = 0;
	std::cin >> number;
	std::vector <int> v (4160);
	for (int i = 0; i < number; ++i) {
		std::string request = "";
		std::cin >> request;

		int hash = 0;
		for (int i = 0; i < request.size(); ++i) {
			hash += request.at(i);
		}

		if (v.at(hash) == 0) {
			std::cout << "OK" << "\n";
		}
	}
}