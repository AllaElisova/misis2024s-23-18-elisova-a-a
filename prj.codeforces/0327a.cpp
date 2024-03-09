#include <iostream>
#include <vector>

int main() {
	int number = 0;
	std::cin >> number;

	std::vector <int> v(0);
	int summa = 0;

	for (int i = 0; i < number; ++i) {
		int a = 0;
		std::cin >> a;
		summa += a;


		if (a == 0) {
			v.push_back(1);
		}
		else {
			v.push_back (-1);
		}
	}

	int cur_summa_v = 0;
	int max_summa_v = -100000;
	//int start = 0;
	//int end = 0;

	for (int i = 0; i < v.size(); ++i) {
		cur_summa_v += v.at(i);
		if (cur_summa_v > max_summa_v) {
			max_summa_v = cur_summa_v;
			//++end;
		}

		if (cur_summa_v < 0) {
			cur_summa_v = 0;
			//start = end + 1;
		}
	}


	std::cout << summa + max_summa_v << std::endl;
	
}