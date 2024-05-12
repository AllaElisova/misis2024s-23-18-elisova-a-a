// not finished
 
#include <iostream>
#include <algorithm>

int main() {
	int length = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> length >> a >> b >> c;

	int var1 = std::min(a, b);
	var1 = std::min(b, c);
	int var3 = std::max(a, b);
	var3 = std::max(b, c);
	int var2 = a + b + c - var1 - var3;

	int answer = 0;
	for (int i = 1; i <= length; ++i) {
		for (int j = 1; j <= length; ++i) {
			int sum = i * var1 + j * var2;
			if ((length - sum) % var3 == 0) {
				int candidate = i + j + (length - sum) / var3;
				answer = std::max(answer, candidate);
			}
		}
	}

	std::cout << answer;
} 