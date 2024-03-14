//not finished

#include <iostream>
#include<vector>

int main() {
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {
		int length = 0;
		std::vector <int> v(0);
		std::cin >> length;

		for (int j = 0; j < length; ++j) {
			int a = 0;
			std::cin >> a;
			v.push_back(a);
		}

		int start = 0;
		int current = 1;
		int count = 0;
		long long int pr = v[0];
		long long sum = v[0];
		while (current < v.size() - 1) {
			pr = pr & v[current];
			sum = sum ^ v[current];
			if (pr > sum) {
				++count;
				++current;
			}
			else if (pr == 0) {
				++start;
				current = start;
				pr = v[current];
				sum = v[current];
			}
			else {
				++current;
			}
		}

		std::cout << count << std::endl;
	}
}