// not finished

// ver 1

/* #include <iostream>
#include <string>

int main() {
	std::string s;
	getline(std::cin, s);

	int number = 0;
	std::cin >> number;

	for (int i = 0; i < number; ++i) {
		int left;
		int right;
		std::cin >> left >> right;

		left -= 1;
		right -= 1;

		char last = s[left];
		int answer = 0;

		while (left < right) {
			++left;
			if (s.at(left) == last) {
				++answer;
			}
			last = s.at(left);
		}
		std::cout << answer << std::endl;
	}
} */

// ver 2

#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string s;
	getline(std::cin, s);

	int number = 0;
	std::cin >> number;

	std::vector <int> data(number * 2);

	for (int i = 0; i < number * 2 - 1; i += 2) {
		int left;
		int right;
		std::cin >> left >> right;

		left -= 1;
		right -= 1;

		data[i] = left;
		data[i + 1] = right;
	}

	int left = data.at(0);
	int right = data.at(1);

	char last = s.at(left);
	int answer = 0;
	int counter = 0;

	while (counter < number * 2) {
			++left;
			if (s.at(left) == last) {
				++answer;
			}
			last = s.at(left);

			if ((left == right) && (counter < number * 2 - 3)) {
				std::cout << answer << std::endl;
				counter += 2;
				left = data.at(counter);
				right = data.at(counter + 1);
				last = s.at(left);
				answer = 0;
			}
			else if ((left == right) && (counter >= number * 2 - 3)) {
				std::cout << answer << std::endl;
				counter += 10;
			}
	}
}
