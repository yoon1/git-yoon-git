#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
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
