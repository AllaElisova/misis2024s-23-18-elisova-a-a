// not finished

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {
		int n = 0;
		std::cin >> n;
		std::vector <int> v(n + 1, 0);
		for (int j = 0; j < n; ++j) {
			int a = 0;
			std::cin >> a;
			v.at(a) += 1;
		}

		std::sort(v.begin(), v.end());
		int max_sim = v.at(n);
		//std::cout << max_sim << std::endl;
		int different = 0;

		for (int j = 0; j < n; ++j) {
			if (v.at(j) > 0) {
				different += 1;
			}
		}

		std::cout << std::min(different, max_sim) << std::endl;
	 }
}