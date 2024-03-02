// not finished

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int lights = 0;
	int length = 0;
	std::cin >> lights >> length;

	std::vector <int> arr(0);

	for (int i = 0; i < lights; ++i) {
		int a;
		std::cin >> a;
		arr.push_back (a);
	}

	int max_answer = 0;
	std::sort(arr.begin(), arr.end());

	int first = -1;
	int last = -1;

	for (int i = 0; i < lights; ++i) {
			if (first != -1) {
				if (last == -1) {
					max_answer = arr.at(i) - first;
					last = arr.at(i);
				}
				else {
					max_answer = std::max(max_answer, arr.at(i) - last);
					last = arr.at(i);
				}
			}
			else {
				first = arr.at(i);
			}
		}

	double d_answer = double(max_answer) / 2.0;

	if (first > d_answer) {
		d_answer = double(first);
	}
	else if (length - last > d_answer) {
		d_answer = double(length - last);
	}

	std::cout << d_answer << std::endl;
}