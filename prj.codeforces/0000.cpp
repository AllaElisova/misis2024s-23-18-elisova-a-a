#include <iostream>
#include <vector>

int main() {
  int number = 0;
  std::cin >> number;

  std::vector <int> groups(4, 0);

  int answer = 0;
  int group = 0;

  for (int i = 0; i < number; ++i) {
    std::cin >> group;
    if (group == 4) {
      answer += 1;
    }
    else {
      groups[group] += 1;
    }
  }

  answer += groups[2] / 2;
  answer += std::min(groups[1], groups[3]);

  if (groups[2] % 2 == 0) {
    if (groups[1] > groups[3]) {
      if ((groups[1] - groups[3]) % 4 == 0) {
        answer += (groups[1] - groups[3]) / 4;
      }
      else {
        answer += (groups[1] - groups[3]) / 4 + 1;
      }
    }
    else if (groups[1] < groups[3]) {
      answer += (groups[3] - groups[1]);
    }
  }
  else {
    answer += 1;
    if (groups[1] > groups[3]) {
      if ((groups[1] - groups[3] - 2) % 4 == 0) {
        answer += ((groups[1] - groups[3] - 2) / 4);
      }
      else {
        answer += ((groups[1] - groups[3] - 2) / 4 + 1);
      }
    }
    else if (groups[1] < groups[3]) {
      answer += (groups[3] - groups[1]);
    }
  }

  std::cout << answer << std::endl;

}