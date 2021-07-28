#include <iostream>
#include <algorithm>
#include <unordered_set>
#define MAX 8

using namespace std;

int solution(int N, int number) {
	int answer = EOF;
	int base = 0;

	//�ּڰ��� 8���� ũ�� -1�� return
	unordered_set<int> numbers[MAX];

	//�־��� N�� �ִ� 8�� ����Ͽ� �����.
	for (int i = 0; i < MAX; i++) {
		base = 10 * base + 1;
		numbers[i].insert(base * N);
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < i; j++) {
			for (auto op1 : numbers[j]) {
				// �� �ǿ����ڵ��� �̿��� ������ ����
				for (auto op2 : numbers[i - j - 1]) {
						numbers[i].insert(op1 + op2); // +
						numbers[i].insert(op1 - op2); // - 
						numbers[i].insert(op1 * op2); // * 
						// ���Ŀ��� ��ȣ�� ��Ģ���길 �����ϰ� ������ ���꿡�� �������� �����Ѵ�.
						if (op2 != 0) { numbers[i].insert(op1 / op2); // ���� ����
					}
				}
			}
		}
		// �־��� number�� N�� ���� ������� ���
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