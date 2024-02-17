#include <iostream>
#include <string>
#include <array>

int main() {
	int k = 0;
	std::cin >> k;

	std::string number;
	std::cin >> number;

	int sum = 0;
	std::array <int, 10> arr{ 0 };

	for (int i = 0; i < number.size(); ++i) {
		int cur;
		cur = int(number[i]) - int('0');
		arr[cur]++;
		sum += cur;
	}
		
	int answer = 0;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < arr[i]; ++j) {
			if (sum < k) {
				answer++;
				sum += (9 - i);
			}
		}
	}

	std::cout << answer << std::endl;

}