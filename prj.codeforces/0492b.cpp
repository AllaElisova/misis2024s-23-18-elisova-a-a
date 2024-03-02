// not finished

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int lights = 0;
	int length = 0;
	std::cin >> lights >> length;

	std::vector <int> arr(length + 1);

	for (int i = 0; i < lights; ++i) {
		int a;
		std::cin >> a;
		arr.at(a) = 1;
	}

	int max_answer = 0;
	std::vector <int> count(0);

	for (int i = 0; i < length + 1; ++i) {
		if (arr.at(i) == 1) {
			if (count.size() != 0) {
				max_answer = std::max(i - count.at(count.size() - 1), max_answer);
				count.push_back(i);
			}
			else {
				count.push_back(i);
			}
		}
	}

	double d_answer = double(max_answer) / 2.0;

	if (count.at(0) > d_answer) {
		d_answer = double(count.at(0));
	}
	else if (length - count.at(lights - 1) > d_answer) {
		d_answer = double(length - count.at(lights - 1));
	}

	std::cout << d_answer << std::endl;
}