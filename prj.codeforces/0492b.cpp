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

	std::vector <int> count(2);
	count.at(0) = -1;
	count.at(1) = -1;

	for (int i = 0; i < length + 1; ++i) {
		if (arr.at(i) == 1) {

			if (count.at(0) != -1) {
				if (count.at(1) == -1) {
					max_answer = i - count.at(0);
					count.at(1) = i;
				}
				else {
					max_answer = std::max(max_answer, i - count.at(1));
					count.at(1) = i;
				}
			}
			else {
				count.at(0) = i;
			}
		}
	}

	double d_answer = double(max_answer) / 2.0;

	if (count.at(0) > d_answer) {
		d_answer = double(count.at(0));
	}
	else if (length - count.at(1) > d_answer) {
		d_answer = double(length - count.at(1));
	}

	std::cout << d_answer << std::endl;
}