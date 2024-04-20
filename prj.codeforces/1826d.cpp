#include <iostream>
#include <vector>

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int length = 0;
		std::cin >> length;
		std::vector<int> v(length);

		for (int j = 0; j < length; ++j) {
			int beauty = 0;
			std::cin >> beauty;
			v.at(j) = beauty;
		}

		std::vector<int> prev_maxim(length);
		std::vector<int> post_maxim(length);

		for (int left = 0; left < length; ++left) {  //левые границы
			prev_maxim.at(left) = v.at(left) + left;
		}

		for (int right = length - 1; right > 0; --right) {  //правые границы
			post_maxim.at(right) = v.at(right) - right;
		}

		for (int j = 1; j < length - 2; ++j) {
			prev_maxim.at(j) = std::max(prev_maxim.at(j), prev_maxim.at(j - 1));
		}

		for (int j = length - 2; j > 0; --j) {
			post_maxim.at(j) = std::max(post_maxim.at(j), post_maxim.at(j + 1));
		}

		int answer = 0;

		for (int j = 1; j < length - 1; ++j) {
			answer = std::max(answer, v.at(j) + prev_maxim.at(j - 1) + post_maxim.at(j + 1));

		}

		std::cout << answer << std::endl;
	}
}