#include <iostream>
#include <string>
#include <stack>
// 괄호의 짝이 맞는지 확인하기 위함
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
		// 최초로 left와 right가 같아졌을 때가 가장 짧은 균형잡힌 괄호 문자열..
		if (left == right) {
			*pos = i + 1; // pos는 v의 위치, u의 길이로 사용할 것이다.
			return ret;
		}
	}
	return true;
}


string solution(string p) {
	// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환한다.
	if (p.empty()) return p;

	int pos;
	bool correct = isCorrect(p, &pos); // u,v로 분리하기 위한 pos key가 반환된다.
	string u = p.substr(0, pos); // 처음부터 pos만큼이 u가 된다.
	string v = p.substr(pos, p.length() - pos); // 전체 길이에서 pos만큼

	// 올바른 괄호 문자열이면 3을 수행하고
	// 1단계부터 다시 수행하는 부분. (solution내용) ==> 재귀적 호출
	// 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환한다.
	if (correct) {
		return u + solution(v); // solution을 재귀적으로 호출
	}

	// 아니면 4를 수행하도록 한다.
	// 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙인다.
	// 4-2. 문자열에 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어붙인다.
	// 4-3. ')'를 다시 붙인다.
	// 4-4. u의 첫번째와 마지막 문자를 제거하고 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙인다.
	// 4-5. 반환한다.
	string answer = "(" + solution(v) + ")";
	for (int i = 1; i < u.length - 1; i++) { // 첫번째 문자 제거, 마지막 문자 제거
		if (u[i] == '(') answer += ")";
		else  answer += "(";
	}
	return answer;
}

int main() {
	return 0;
}