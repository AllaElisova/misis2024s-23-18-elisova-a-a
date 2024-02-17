// not finished
 
#include <iostream>
#include <vector>

int main() {
	int n;
	int m = 0;
	std::cin >> n >> m;

	std::vector<int> arr (n, 0);
	std::vector<int> numbers (100001, 0);

	for (int i = 0; i < n; ++i) {
		int number = 0;
		std::cin >> number;
		arr.at(i) = number;
		numbers.at(number) = 1;
	}

	for (int j = 0; j < m; ++j) {
		std::vector <int>numbers1 = numbers;

		int low = 0;
		std::cin >> low;

		int answer = 0;
		for (int k = n - 1; k > low - 2; --k) {
			if (numbers1[arr[k]] == 1) {
				answer++;
				numbers1[arr[k]] = 0;
			}
		}

		std::cout << answer <<std::endl;
	}
}