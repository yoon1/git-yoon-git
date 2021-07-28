#include <iostream>
#include <algorithm>
#define MAX 100

using namespace std;

int N, L, result;
int map[MAX][MAX];

void circuit(int i, bool flag) {
	int cnt = 1;
	for (int j = 0; j < N - 1; j++ ) {
		int d = flag ? map[i][j + 1] - map[i][j] : map[j + 1][i] - map[j][i];
		if (d == 0) cnt++; // ???? ?¢©?? ¡Æ???¢¬? ++;
		else if (d == 1 && cnt >= L) cnt = 1;
		else if (d == -1 && cnt >= 0) cnt = -L + 1;  
		else return; // 2?¡© ???? ?¡À??©©?¢¬? return
	}
	if (cnt >= 0) result += 1; // ok
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		circuit(i,true);
		circuit(i,false);
	}
	cout << result;
	return 0;
}