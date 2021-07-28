#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pos {
	int pid;
	int did;
}Pos;

char cube[6][9];// 6개의 면.
// 위 - 0 - 흰 & 아래 - 1-  노 & 앞 - 2 - 빨 & 뒤 - 3 - 오 & 왼 - 4 - 초 & 오 - 5 - 파

Pos dat[6][12] = {
	{{3,7},{3,8},{3,9},{5,1},{5,4},{5,7},{2,3},{2,2},{2,1},{4,9},{4,6},{4,3}}, // 위
	{{2,7},{2,8},{2,9},{5,9},{5,6},{5,3},{3,3},{3,2},{3,1},{4,1},{4,4},{4,7}}, // 아래
	{{0,7},{0,8},{0,9},{5,7},{5,8},{5,9},{1,3},{1,2},{1,1},{4,7},{4,8},{4,9}}, // 앞
	{{1,7},{1,8},{1,9},{5,3},{5,2},{5,1},{0,3},{0,2},{0,1},{4,3},{4,2},{4,1}}, // 뒤
	{{3,1},{3,4},{3,7},{0,1},{0,4},{0,7},{2,1},{2,4},{2,7},{1,1},{1,4},{1,7}}, // 왼
	{{0,9},{0,6},{0,3},{3,9},{3,6},{3,3},{1,9},{1,6},{1,3},{2,9},{2,6},{2,3}} // 오른
};
int plane_dat[8] = { 0,1,2,5,8,7,6,3 };

int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N;
		for (int i = 0; i < 9; i++) { // 초기값
			cube[0][i] = 'w';
			cube[1][i] = 'y';
			cube[2][i] = 'r';
			cube[3][i] = 'o';
			cube[4][i] = 'g';
			cube[5][i] = 'b';
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			char nm;
			char dir;
			cin >> nm >> dir;
			int inm = (nm == 'U') ? 0 : (nm == 'D') ? 1 : (nm == 'F') ? 2 : (nm == 'B') ? 3 : (nm == 'L') ? 4 : 5;

			// 돌릴 데이터 담기
			vector<char> t(12);
			vector<char> tplane(8);
			Pos tdat[12];

			for (int i = 0; i < 12; i++) {
				tdat[i] = dat[inm][i]; // pos다 담음.
				t[i] = cube[tdat[i].pid][tdat[i].did - 1];
			}
			for (int i = 0; i < 8; i++) 
				tplane[i] = cube[inm][plane_dat[i]];

			// 돌리기
			if (dir == '-') { // left
				rotate(t.begin(), t.begin() + 3, t.end());
				rotate(tplane.begin(), tplane.begin() + 2, tplane.end());
			}
			else {// right
				rotate(t.rbegin(), t.rbegin() + 3, t.rend());
				rotate(tplane.rbegin(), tplane.rbegin() + 2, tplane.rend());
			}

			// 다시 놓기
			for (int i = 0; i < 12; i++) 
				cube[tdat[i].pid][tdat[i].did - 1] = t[i];

			for (int i = 0; i < 8; i++) 
				cube[inm][plane_dat[i]] = tplane[i];
		}
		for (int i = 1; i <= 9; i++) { // 초기값
			cout << cube[0][i - 1];
			if (i % 3 == 0) cout << "\n";
		}
	}
	return 0;
}