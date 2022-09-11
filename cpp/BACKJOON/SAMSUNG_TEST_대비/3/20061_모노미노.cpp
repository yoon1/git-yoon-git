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
		for (int i = 4; i <= 9; i++) { //�Ķ���
			if (i == 9) { ground[x][i] = 1; break; }
			if (ground[x][i + 1] == 1) { ground[x][i] = 1; break; }
		}
		for (int i = 4; i <= 9; i++) { //�ʷϻ�
			if (i == 9) { ground[i][y] = 1; break; }
			if (ground[i + 1][y] == 1) { ground[i][y] = 1; break; }
		}
	}
	else if (t == 2) {
		int tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //�Ķ���
			if (ground[x][i] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[x][tmpindex - 1] = 1; ground[x][tmpindex - 2] = 1;

		tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //�ʷϻ�
			if (ground[i][y] == 1 || ground[i][y + 1] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[tmpindex - 1][y] = 1; ground[tmpindex - 1][y + 1] = 1;
	}
	else {
		int tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //�Ķ���
			if (ground[x][i] == 1 || ground[x + 1][i] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[x][tmpindex - 1] = 1; ground[x + 1][tmpindex - 1] = 1;
		tmpindex = 10;
		for (int i = 4; i <= 9; i++) { //�ʷϻ�
			if (ground[i][y] == 1) {
				tmpindex = i;
				break;
			}
		}
		ground[tmpindex - 1][y] = 1; ground[tmpindex - 2][y] = 1;
	}
}

void delblock() {
	//�Ķ���
	for (int i = 9; i >= 6; i--) {
		bool checking = false;
		for (int j = 0; j < 4; j++) {
			if (ground[j][i] == 0) { checking = true; break; }
		}
		if (checking == false) { //4����� �������
			resultscore++;
			for (int k = i; k >= 4; k--) { //�̵���Ű��
				for (int l = 0; l < 4; l++) { ground[l][k] = ground[l][k - 1]; }
			}
			i++; // ������ �ѹ��� ������ ��츦 ���ؼ� �̵���Ų�� �ٽ� �� ��,�ĺ��� Ȯ���ؾߵ�
		}
	}
	//�ʷϻ�
	for (int i = 9; i >= 6; i--) {
		bool checking = false;
		for (int j = 0; j < 4; j++) {
			if (ground[i][j] == 0) { checking = true; break; }
		}
		if (checking == false) {
			resultscore++;
			for (int k = i; k >= 4; k--) { //�̵���Ű��
				for (int l = 0; l < 4; l++) { ground[k][l] = ground[k - 1][l]; }
			}
			i++; // ������ �ѹ��� ������ ��츦 ���ؼ� �̵���Ų�� �ٽ� �� ��,�ĺ��� Ȯ���ؾߵ�
		}
	}
}

void moveblock() {
	//���� �Ķ���
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
	//���� �ʷϻ�
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
		fillnemo(); // ��� �ʷϻ� �Ķ������� �̵���Ű��
		delblock(); // 4����� ���� ��,�Ǵ� �� ���� (���� ȹ��)
		moveblock(); // �����ʷ�, �����Ķ����� ����� ���� ��� �̵�
	}
	getblock();
	cout << resultscore << "\n";
	cout << resultblock << "\n";

	return 0;
}