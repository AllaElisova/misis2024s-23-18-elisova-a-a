#include <iostream>

int main() {
	int n, m, a, b;
	std::cin >> n >> m >> a >> b;

	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		if (i % m == 0) {
			answer += std::min(a * m, b);
		}

		//answer += (a * m < b) * a;
	}

	answer += (a * (n % m) < b) * a * (n % m);
	answer += (a * (n % m) >= b) * b;
	std::cout << answer;
}