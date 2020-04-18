#include <iostream>
#include <string>
#include <stack>
#define MAX 500

using namespace std;

int main() {
	int N = 0;
	int M = 0;
	string board[MAX] = {};
	stack<string> stk;

	cin >> N >> M; // board판 그리기
	
	for (int i = 1; i <= N; i++) {
		cin >>  board[i];
		board[i] = "." + board[i] + ".";
	}

	for (int j = 0; j <= N+1; j++) { // 보드 벽치기
		board[0] += ".";
		board[N+1] += ".";
	} 
	/*
	for (int i = 0; i <= N+1; i++) {
		cout << board[i] << endl;
	}  
	*/ 
		
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (board[y][x] == 'B') {
				
			}
		}
	}
	
	return 0;
}
