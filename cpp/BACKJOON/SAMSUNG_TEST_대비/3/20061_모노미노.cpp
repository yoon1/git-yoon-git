#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int N, t, x, y;
int ground[10][10]; //0~9
int resultscore;
int resultblock;

void fillnemo() {
	if (t == 1) {
		for (int i = 4; i <= 9; i++) { //파란색
			if (i == 9) { ground[x][i] = 1; break; }
			if (ground[x][i + 1] == 1) { ground[x][i] = 1; break; }
		}
		for (int i = 4; i <= 9; i++) { //초록색
			if (i == 9) { ground[i][y] = 1; break; }
			if (ground[i + 1][y] == 1) { ground[i][y] = 1; break; }
		}
	}
	else if (t == 2) {
		int tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //파란색
			if (ground[x][i] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[x][tmpindex - 1] = 1; ground[x][tmpindex - 2] = 1;

		tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //초록색
			if (ground[i][y] == 1 || ground[i][y + 1] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[tmpindex - 1][y] = 1; ground[tmpindex - 1][y + 1] = 1;
	}
	else {
		int tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //파란색
			if (ground[x][i] == 1 || ground[x + 1][i] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[x][tmpindex - 1] = 1; ground[x + 1][tmpindex - 1] = 1;
		tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //초록색
			if (ground[i][y] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[tmpindex - 1][y] = 1; ground[tmpindex - 2][y] = 1;
	}
}

void delblock() {
	//파란색
	for (int i = 9; i >= 6; i--) {
		bool checking = false;
		for (int j = 0; j < 4; j++) {
			if (ground[j][i] == 0) { checking = true; break; }
		}
		if (checking == false) { //4블록이 꽉찬경우
			resultscore++;
			for (int k = i; k >= 4; k--) { //이동시키기
				for (int l = 0; l < 4; l++) { ground[l][k] = ground[l][k - 1]; }
			}
			i++; // 두줄이 한번에 꽉차는 경우를 위해서 이동시킨후 다시 그 행,렬부터 확인해야됨
		}
	}
	//초록색
	for (int i = 9; i >= 6; i--) {
		bool checking = false;
		for (int j = 0; j < 4; j++) {
			if (ground[i][j] == 0) { checking = true; break; }
		}
		if (checking == false) {
			resultscore++;
			for (int k = i; k >= 4; k--) { //이동시키기
				for (int l = 0; l < 4; l++) { ground[k][l] = ground[k - 1][l]; }
			}
			i++; // 두줄이 한번에 꽉차는 경우를 위해서 이동시킨후 다시 그 행,렬부터 확인해야됨
		}
	}
}

void moveblock() {
	//연한 파란색
	bool checking = false;
	int checkingcount = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (ground[j][i] == 1) { checkingcount++; break; }
		}
	}
	if (checkingcount != 0) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				ground[j][i] = ground[j][i - checkingcount];
			}
		}
	}
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			ground[j][i] = 0;
		}
	}
	//연한 초록색
	checking = false;
	checkingcount = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (ground[i][j] == 1) { checkingcount++; break; }
		}
	}
	if (checkingcount != 0) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				ground[i][j] = ground[i - checkingcount][j];
			}
		}
	}
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			ground[i][j] = 0;
		}
	}
}
void watchground() {
	cout << endl;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			cout << ground[i][j];
		}
		cout << endl;
	}
}
void getblock() {
	for (int i = 6; i <= 9; i++) {
		for (int j = 0; j < 4; j++) {
			if (ground[j][i] == true) resultblock++;
		}
	}
	for (int i = 6; i <= 9; i++) {
		for (int j = 0; j < 4; j++) {
			if (ground[i][j] == true) resultblock++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		cin >> t >> x >> y;
		fillnemo(); // 블록 초록색 파란색으로 이동시키기
		delblock(); // 4블록이 꽉찬 행,또는 렬 삭제 (점수 획득)
		moveblock(); // 연한초록, 연한파란색에 블록이 있을 경우 이동
	}
	getblock();
	cout << resultscore << "\n";
	cout << resultblock << "\n";

	return 0;
}