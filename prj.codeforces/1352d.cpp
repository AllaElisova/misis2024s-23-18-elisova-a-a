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

			if (last_pos == 's') {  //�������� ����� ����� ��� ������ current
				++current;
			}
	
			else if (last_pos == 'e') {  // �� ��� ��������
				--current;
			}

			cur_sum += v.at(current);  // �������� ����� ������ �������� ��� ���

			if (current > end) {  //���� ��� ������� � ����� �� �����
				++answer;
				answer_a += cur_sum;  // ����� �����
				start = end;    // �� ������ �� ����� ����� ������ ������
				break;  // ����
			}
			else if (current < start) {  // ���� ��� � ����� � ����� �� ������
				++answer;
				answer_b += cur_sum;  // ������ ����
				end = start; 
				break;    // �� ������ ���� ���� �� �����
			}

			if (cur_sum > last_sum) {  // ���� �� �� ��� � ���� ������� �������� ��������
				++answer;  // ����� ����� ������
				last_sum = cur_sum;

				if (last_pos == 'e') {  // ���� ��� ���� ������ ������ ��� � ������
					answer_b += cur_sum;
					end = current - 1;
					last_pos = 's';
					current = start;
					cur_sum = v.at(start);
				}

				else if (last_pos == 's') {  // ���� ����� ������ ������ ������ ��� � �����
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