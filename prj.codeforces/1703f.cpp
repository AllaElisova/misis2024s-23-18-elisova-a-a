#include <iostream>
#include <vector>

int main() {
	int times = 0;
	std::cin >> times;

	for (int i = 0; i < times; ++i) {
		int length = 0;
		std::cin >> length;

		std::vector <long long int> v(length+1);

		for (int j = 1; j <= length; ++j) {
			long long int elem = 0;
			std::cin >> elem;
			v.at(j) = elem;
		}

		long long int answer = 0;
		std::vector <int> vv;

		for (int j = 1; j <= length; ++j) {
			if (v.at(j) < j) {
				long long int res = lower_bound(vv.begin(), vv.end(), v.at(j)) - vv.begin();
				answer += res;
				vv.push_back(j);
			}
		}

		std::cout << answer << "\n";
	}
}