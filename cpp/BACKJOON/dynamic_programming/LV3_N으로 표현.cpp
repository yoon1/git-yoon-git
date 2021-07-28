#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int _answer = MAX;

void dfs(int cnt, int _number, int N, int number) {
	// 8 ���� ũ�� ����
	if (cnt >= MAX || cnt >= _answer) return; 

	if (number == _number)
		_answer = min(_answer, cnt);

	// ���� 1�ڸ� ~ 8�ڸ�
	int n = 0;
	for (int i = 0; i < 8; i++) {
		n = (n * 10) + N; // 1 ~ 8
		// cnt�� ����� �� ��ŭ +
		dfs(cnt + i + 1, _number + n, N, number); // +
		dfs(cnt + i + 1, _number - n, N, number); // -
		if (_number != 0) {// 0 �� �ƴ� ��쿡��
			dfs(cnt + i + 1, _number * n, N, number); // *
			dfs(cnt + i + 1, _number / n, N, number); // /
		}
	}
}

int solution(int N, int number) {
	int answer = 0;
	dfs(0, 0, N, number);
	answer = (_answer == MAX) ? -1 : _answer;
	return answer;
}

int main() {
	cout << solution(5, 12);
	return 0;
}