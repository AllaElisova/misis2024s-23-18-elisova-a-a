#include <iostream>

int main() {
	int lights = 0;
	int product = 0;

	std::cin >> lights >> product;

	int answer = lights;

	while (lights >= product) {
		lights = lights - product + 1;
		answer += 1;
	}

	std::cout << answer << std::endl;
}
