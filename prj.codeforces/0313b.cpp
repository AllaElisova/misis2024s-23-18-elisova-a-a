// not finished

#include <iostream>
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
}