#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {
		int length = 0;
		std::cin >> length;
		std::vector<int> v(length + 1);

		for (int j = 1; j <= length; ++j) {
			int elem = 0;
			std::cin >> elem;
			v.at(j) = elem;
		}

		std::sort(v.begin(), v.end());	
		long long answer = 0;

		for (int j = length ; j > 0; j--) {
			if ((length - j) % 2 == 0) {
				if (v.at(j) % 2 == 0) {
					answer += v.at(j);
				}
			}

			else {
				if (v.at(j) % 2 == 1) {
					answer -= v.at(j);
				}
			}
		}

		if (answer == 0) {
			std::cout << "Tie" << std::endl;
		}
		else if (answer > 0) {
			std::cout << "Alice" << std::endl;
		}
		else {
			std::cout << "Bob" << std::endl;
		}
	}
}