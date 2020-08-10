#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���� ���� < ���� ����
vector<int> solution(int brown, int yellow) {
	vector<int> answer(2);
	// yellow�� ���� ����
	for (int i = 1; i <= yellow ; i++) {
		int garo, sero = i;
		if (yellow % sero == 0) {
			garo = yellow / sero;
			if (((garo * 2) + (sero * 2) + 4) == brown) {
				answer[0] = sero + 2;// brown garo
				answer[1] = garo + 2;// brown sero
			}
		}
	}
	return answer;
}

int main() {
	vector<int> v = solution(24, 24);
	return 0;
}
