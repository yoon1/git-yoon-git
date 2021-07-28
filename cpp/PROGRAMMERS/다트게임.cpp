#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> point;

// bonus
int setBonus(int a, char op) {
	return pow(a, point[op]);
}
// option
int setOption(int a, char op) {
	if (op == '*') return a*2;
	return -a;
}
int solution(string dartResult) {
	point['S'] = 1, point['D'] = 2, point['T'] = 3;
	int answer[4];
	int idx = 0;
	string snum = "";
	int size = dartResult.length();
	for (int i = 0; i < size; i++) {
		int c = dartResult[i];
		if (c >= '0' && c <= '9') {
			if (snum == "") idx++;
			snum += c;
		}
		else if (isalpha(c)) {// alpha - bonus
			int num = stoi(snum);
			snum = "";
			answer[idx] = setBonus(num, c);
		}
		else { // option
			if (c == '*' && idx > 1)
				answer[idx - 1] = setOption(answer[idx-1], c);
			answer[idx] = setOption(answer[idx], c);
		}
	}
	cout << answer[1] << " ," << answer[2] << ", " << answer[3] << endl;
	return answer[1] + answer[2] + answer[3];
}
int main() {
	cout << solution("1D2S#10S") << endl;
	cout << solution("1D2S0T") << endl;
	cout << solution("1S*2T*3S") << endl;
	cout << solution("1D#2S*3S") << endl;
	cout << solution("1T2D3D#") << endl;
	cout << solution("1D2S3T*") << endl;
	return 0;
}