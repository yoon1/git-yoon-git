#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

deque<int> dq;
deque<char> operand;

void pushIntDq(string str) {
	if (str == "") return;
	int num = atoi(str.c_str());
	dq.push_back(num);
}

void parsingStr(int N, string str) {
	string intWord = "";
	for (int i = 1; i < str.size() - 1; i++) {
		if (str.at(i) != ',') intWord += str[i];
		else {
			pushIntDq(intWord);
			intWord = "";
		}
	}
	pushIntDq(intWord);
}

void print(bool order) {
	string result = "[";
	if (!order)
		reverse(dq.begin(), dq.end());
	for (int i = 0; i < dq.size(); i++) {
		result += to_string(dq[i]);
		if ( i != dq.size() - 1 ) result += ",";
	}
	result += "]";
	cout << result << "\n"; 
}

bool processing(char op, bool& order) {
	if (op == 'R')
		order = !order;
	else { 
		if (dq.empty()) {
			cout << "error\n";
			return false;
		}
		if (!order)
			dq.pop_back();
		else
			dq.pop_front();
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N;
	string str;

	cin >> T;
	for (int t = 0; t < T; t++) {
		// 초기화
		dq.clear();
		operand.clear();
		cin >> str;
		for (int i = 0; i < str.size(); i++)
			operand.push_back(str.at(i)); // operand 등록

		cin >> N;
		cin >> str;
		// # 문자열 파싱 및 dq에 정수 입력
		parsingStr(N, str);

		bool order = true;
		bool err_flag = false;
		for (int i = 0; i < operand.size(); i++) {
			if (!processing(operand[i], order)) {
				err_flag = true;
				break;
			}
		}
		if (!err_flag)
			print(order);
	}
	return 0;
}