//not finished

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {

		int length = 0;
		int size = 0;
		std::vector <int> v(0);
		std::cin >> length;

		for (int j = 0; j < length; ++j) {
			int a = 0;
			std::cin >> a;
			v.push_back(a);
			++size;
		}

		std::sort(v.begin(), v.end());

		int start = 0;
		int current = 1;
		int count = 0;
		long long int pr = v[0];
		long long int sum = v[0];

		while (start < size - 1) {
			pr = pr & v.at(current);
			sum = sum ^ v.at(current);

			if (pr == 0) {
				++start;
				pr = v.at(start);
				sum = v.at(start);
				current = start + 1;
				continue;
			}

			if (pr >= sum) {
				++count;
				++current;
			}
			else {
				++current;
			}

			if (current == size) {
				++start;
				pr = v.at(start);
				sum = v.at(start);
				current = start + 1;
			}
		}

		std::cout << count << std::endl;
	}
}