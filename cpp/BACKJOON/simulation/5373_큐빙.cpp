#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// �� - 0 - �� // �Ʒ� - 1-  �� // �� - 2 - �� //  �� - 3 - �� // �� - 4 - �� // �� - 5 - ��
typedef struct pos {
	int plane; // ���� ��ǥ
	int point; // ���� ��ǥ
}Pos;

char cube[6][9];// 6���� ��. 9���� ��

Pos around_dat[6][12] = { // ȸ���� ���� (plane, ��)
	{{3,7},{3,8},{3,9},{5,1},{5,4},{5,7},{2,3},{2,2},{2,1},{4,9},{4,6},{4,3}}, // ��
	{{2,7},{2,8},{2,9},{5,9},{5,6},{5,3},{3,3},{3,2},{3,1},{4,1},{4,4},{4,7}}, // �Ʒ�
	{{0,7},{0,8},{0,9},{5,7},{5,8},{5,9},{1,3},{1,2},{1,1},{4,7},{4,8},{4,9}}, // ��
	{{1,7},{1,8},{1,9},{5,3},{5,2},{5,1},{0,3},{0,2},{0,1},{4,3},{4,2},{4,1}}, // ��
	{{3,1},{3,4},{3,7},{0,1},{0,4},{0,7},{2,1},{2,4},{2,7},{1,1},{1,4},{1,7}}, // ��
	{{0,9},{0,6},{0,3},{3,9},{3,6},{3,3},{1,9},{1,6},{1,3},{2,9},{2,6},{2,3}} // ����
};
int target_dat[8] = { 0,1,2,5,8,7,6,3 }; // ȸ���� ��
int main() {
	int T; 
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N;
		for (int i = 0; i < 9; i++) { // �ʱⰪ
			cube[0][i] = 'w', cube[1][i] = 'y',cube[2][i] = 'r',cube[3][i] = 'o',cube[4][i] = 'g',cube[5][i] = 'b';
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			char nm;  // ���� ��
			char dir; // - : �ݽð�, + : �ð�
			cin >> nm >> dir;
			int inm = (nm == 'U') ? 0 : (nm == 'D') ? 1 : (nm == 'F') ? 2 : (nm == 'B') ? 3 : (nm == 'L') ? 4 : 5;

			// ���� ������ ���
			vector<char> t_around(12); // around
			vector<char> t_target(8);
			Pos tdat[12]; // around_dat(temp)
			
			for (int i = 0; i < 12; i++) {
				tdat[i] = around_dat[inm][i]; 
				t_around[i] = cube[tdat[i].plane][tdat[i].point - 1];
			}
			for (int i = 0; i < 8; i++) {
				t_target[i] = cube[inm][target_dat[i]];
			}
			
			// ������
			if (dir == '-') { // left
				rotate(t_around.begin(), t_around.begin() + 3, t_around.end());
				rotate(t_target.begin(), t_target.begin() + 2, t_target.end());
			}
			else {// right
				rotate(t_around.rbegin(), t_around.rbegin() + 3, t_around.rend());
				rotate(t_target.rbegin(), t_target.rbegin() + 2, t_target.rend());
			}

			// �ٽ� ����
			for (int i = 0; i < 12; i++) {
				cube[tdat[i].plane][tdat[i].point - 1] = t_around[i];
			}
			for (int i = 0; i < 8; i++) {
				cube[inm][target_dat[i]] = t_target[i];
			}
		}
		for (int i = 1; i <= 9; i++) { // �ʱⰪ
			cout << cube[0][i - 1];
			if (i % 3 == 0) cout << "\n";
		}
	}
	return 0;
}