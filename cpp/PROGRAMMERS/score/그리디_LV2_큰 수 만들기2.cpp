#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string solution(string number, int k) {
	for (int i = 0; i < number.size() - k; ++i) {
		auto iter = std::max_element(number.begin() + i, number.begin() + i + k + 1);
		if (iter != number.begin() + i) {
			k = k - std::distance(number.begin() + i, iter);
			number.erase(number.begin() + i, iter);
		}
	}
	number.erase(number.end() - k, number.end());
	return number;
}

/* 
string solution(string number, int k) {
	string answer = "";
	int start = -1;
	for (int i = 0; i < number.length() - k; i++) {
		char t = 0; // max
		for (int j = start + 1; j <= k + i; j++) {
			if (t < number[j]) {
				start = j;
				t = number[j];
			}
		}
		answer += t ;
	}
	return answer;
}
*/
/* 
string solution(string number, int k) {
	string answer = "";
	answer = number.substr(k);
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		do {
			if (number[i] >= answer[j]) {
				swap(answer[j], number[i]);
				j++;
			}
			else {
				break;
			}
		} while (1);
	}
	return answer;
}
*/
int main() {
	cout << solution("1231234", 3) << endl;
	return 0;
}