#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[13];
int N;
int answer;
bool promissing(int row) {
	for (int col = 0; col < row; col++) {
		if ((a[col] == a[row]) || abs(a[row] - a[col]) == abs(row - col))
			return false;
	}
	return true;
}

void backtracking(int row) {
	if (row == N)
		answer++;
	for (int i = 0; i < N; i++) {
		a[row] = i;
		if (promissing(row)) 
			backtracking(row+1);
	}
}
int solution(int n) {
	N = n;
	backtracking(0);
	return answer;
}

int main() {
	cout << solution(1) << endl;
	return 0;
}