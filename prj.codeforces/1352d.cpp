// not finished

#include <iostream>
#include <vector>

int main(){
	int times = 0;
	std::cin >> times;
	for (int i = 0; i < times; ++i) {

		std::vector <int> v(0);
		int number = 0;
		std::cin >> number;
		for (int j = 0; j < number; ++j) {
			int c = 0;
			std::cin >> c;
			v.push_back(c);
		}

		int start = 1;
		int end = number - 1;
		int current = number;
		int last_sum = v.at(0);
		int cur_sum = 0;
		char last_pos = 'e';
		int answer = 1;
		int answer_a = v.at(0);
		int answer_b = 0;

		while (start < end) {

			if (last_pos == 's') {  //проверка чтобы знать как менять current
				++current;
			}
	
			else if (last_pos == 'e') {  // всё ещё проверка
				--current;
			}

			cur_sum += v.at(current);  // поменяли сумму дальше проверим чья она

			if (current > end) {  //если шли сначала и дошли до конца
				++answer;
				answer_a += cur_sum;  // лавры алисе
				start = end;    // всё хватит не дадим алисе больше конфет
				break;  // пока
			}
			else if (current < start) {  // если шли с конца и дошли до начала
				++answer;
				answer_b += cur_sum;  // лаввры бобу
				end = start; 
				break;    // всё хватит бобу тоже не дадим
			}

			if (cur_sum > last_sum) {  // если вы всё ещё с нами пробуем обновить максимум
				++answer;  // ходов стало больше
				last_sum = cur_sum;

				if (last_pos == 'e') {  // если боб смог сбесть больше идём в начало
					answer_b += cur_sum;
					end = current - 1;
					last_pos = 's';
					current = start;
					cur_sum = v.at(start);
				}

				else if (last_pos == 's') {  // если алиса смогла съесть больше идём в конец
					answer_a += cur_sum;
					start = current + 1;
					last_pos = 'e';
					current = end;
					cur_sum = v.at(end);
				}
			}
			
		}
		std::cout << answer << ' ' << answer_a << ' ' << answer_b << std::endl;
	}
}