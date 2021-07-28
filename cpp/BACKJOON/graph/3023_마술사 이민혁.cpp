#include <iostream>

using namespace std;

/*
**(i, j) : i 행, j 열 이라고 가정.**
**(1) 90도 회전**

( i , j ) ⇒ ( j , n - i - 1 )
**(2) x축 대칭**

( i , j ) ⇒  ( n - i - 1 , j )
**(3) y축 대칭**

( i , j ) ⇒  ( i , n - j - 1 )

**(4) 점대칭**
( i ,  j ) ⇒ ( n - i - 1 , n - j - 1 )
*/
int R, C;
int A, B; // 에러의 위치
char board[101][101];

void under() {
	char t_board[101][101] = {};
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < 2*C; c++) {
			t_board[R - r - 1][c] = board[r][c];
		}
	}
	for (int r = R; r < 2 * R; r++) {
		for (int c = 0; c < 2 * C; c++) {
			board[r][c] = t_board[r-R][c];
		}
	}
}

void right() {
	char t_board[51][51] = {};
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			t_board[r][C - c - 1] = board[r][c];
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = C; c < 2*C; c++) {
			board[r][c] = t_board[r][c-C];
		}
	}
}

int main() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> board[r][c];
		}
		char c;
		scanf("\c", &c); // enter
	}
	cin >> A >> B;

	// 오른쪽(y축)
	right();
	
	// 아래쪽(x축)
	under();

	// 변환
	board[A - 1][B - 1] = (board[A - 1][B - 1] == '#') ? '.' : '#';
	
	for (int r = 0; r < 2 * R; r++) {
		for (int c = 0; c < 2 * C; c++) {
			cout << board[r][c];
		}
		cout << endl;
	}

	return 0;
}
