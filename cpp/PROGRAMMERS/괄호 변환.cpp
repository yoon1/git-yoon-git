#include <iostream>
#include <string>
#include <stack>
// ��ȣ�� ¦�� �´��� Ȯ���ϱ� ����
using namespace std;

bool isCorrect(string str, int* pos) {
	bool ret = true;
	int left = 0, right = 0;
	stack<char> mystack;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') {
			left++;
			mystack.push('(');
		}
		else {
			right++;
			if (mystack.empty())
				ret = false;
			else
				mystack.pop();
		}
		// ���ʷ� left�� right�� �������� ���� ���� ª�� �������� ��ȣ ���ڿ�..
		if (left == right) {
			*pos = i + 1; // pos�� v�� ��ġ, u�� ���̷� ����� ���̴�.
			return ret;
		}
	}
	return true;
}


string solution(string p) {
	// 1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�Ѵ�.
	if (p.empty()) return p;

	int pos;
	bool correct = isCorrect(p, &pos); // u,v�� �и��ϱ� ���� pos key�� ��ȯ�ȴ�.
	string u = p.substr(0, pos); // ó������ pos��ŭ�� u�� �ȴ�.
	string v = p.substr(pos, p.length() - pos); // ��ü ���̿��� pos��ŭ

	// �ùٸ� ��ȣ ���ڿ��̸� 3�� �����ϰ�
	// 1�ܰ���� �ٽ� �����ϴ� �κ�. (solution����) ==> ����� ȣ��
	// 3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�Ѵ�.
	if (correct) {
		return u + solution(v); // solution�� ��������� ȣ��
	}

	// �ƴϸ� 4�� �����ϵ��� �Ѵ�.
	// 4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���δ�.
	// 4-2. ���ڿ��� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾���δ�.
	// 4-3. ')'�� �ٽ� ���δ�.
	// 4-4. u�� ù��°�� ������ ���ڸ� �����ϰ� ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���δ�.
	// 4-5. ��ȯ�Ѵ�.
	string answer = "(" + solution(v) + ")";
	for (int i = 1; i < u.length - 1; i++) { // ù��° ���� ����, ������ ���� ����
		if (u[i] == '(') answer += ")";
		else  answer += "(";
	}
	return answer;
}

int main() {
	return 0;
}