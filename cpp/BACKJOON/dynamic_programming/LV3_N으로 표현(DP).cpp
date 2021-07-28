#include <iostream>
#include <algorithm>
#include <unordered_set>
#define MAX 8

using namespace std;

int solution(int N, int number) {
	int answer = EOF;
	int base = 0;

	//최솟값이 8보다 크면 -1을 return
	unordered_set<int> numbers[MAX];

	//주어진 N을 최대 8번 사용하여 만든다.
	for (int i = 0; i < MAX; i++) {
		base = 10 * base + 1;
		numbers[i].insert(base * N);
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < i; j++) {
			for (auto op1 : numbers[j]) {
				// 각 피연산자들을 이용해 연산을 수행
				for (auto op2 : numbers[i - j - 1]) {
						numbers[i].insert(op1 + op2); // +
						numbers[i].insert(op1 - op2); // - 
						numbers[i].insert(op1 * op2); // * 
						// 수식에는 괄호와 사칙연산만 가능하고 나누기 연산에서 나머지는 무시한다.
						if (op2 != 0) { numbers[i].insert(op1 / op2); // 연산 수행
					}
				}
			}
		}
		// 주어진 number가 N을 통해 만들어진 경우
		if (numbers[i].count(number) > 0) {
			answer = i + 1; 
			break;
		}
	}
	return answer;
}

int main() {
	cout << solution(5, 12);
	return 0;
}