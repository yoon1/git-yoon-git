#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;
	int t;
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	for (int i = a; i <= b; i++)
		answer += i;
	return answer;
}

int main() {
	cout << solution(3, 5) << endl;
}


124³ª¶ó
=> 
1 2 3 4 5 