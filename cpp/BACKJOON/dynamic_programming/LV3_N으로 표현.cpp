#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int _answer = MAX;

void dfs(int cnt, int _number, int N, int number) {
	// 8 보다 크면 종료
	if (cnt >= MAX || cnt >= _answer) return; 

	if (number == _number)
		_answer = min(_answer, cnt);

	// 숫자 1자리 ~ 8자리
	int n = 0;
	for (int i = 0; i < 8; i++) {
		n = (n * 10) + N; // 1 ~ 8
		// cnt에 사용한 수 만큼 +
		dfs(cnt + i + 1, _number + n, N, number); // +
		dfs(cnt + i + 1, _number - n, N, number); // -
		if (_number != 0) {// 0 이 아닌 경우에만
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