#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int m[101][101][2] = { 0 };
int N;
bool check(int x, int y) {
	bool rslt = true;
	if (m[x][y][0] > 0) { // ��� 
		if (y == 0  // ���ٴ��� ���
			|| m[x][y - 1][0] == 1 // �ؿ� ����� �ְų�
			|| m[x][y][1] == 1 // ���� ��ġ�Ǿ� �ְų�
			|| (x > 0 && m[x - 1][y][1] == 1))  // ���� ���ʿ� ��ġ�Ǿ� �ְų�.
		{
			rslt = true;
		}
		else
			return false;
	}
	if (m[x][y][1] > 0) { // ��
		if ((y > 0 && m[x][y - 1][0] == 1)  //�ؿ� ����� �ְų�.
			|| (x < N && y > 0 && m[x + 1][y - 1][0] == 1) //  �ؿ� (�����ʿ�) ����� ��ġ�Ǿ� �ְų� - ���ʿ� ����� ������ ����.
			|| (x > 0 && x < N && m[x-1][y][1] == 1 && m[x + 1][y][1] == 1))// �翷�� ���� ��ġ�Ǿ� �ִ� ���.) 
		{
			rslt = true;
		}
		else
			return false;
	}
	return rslt;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int type = build_frame[i][2]; // 0 : ���, 1 : ��
		int act = build_frame[i][3]; // 1 : ��ġ, 0 : ����

		cout << "#(" << x << "," << y << ")" << endl;
		if (act == 1) { // ��ġ
			if (type == 0) {
				m[x][y][0] = m[x][y][0] + 1;
				if (!check(x,y))
					m[x][y][0] = m[x][y][0] - 1;
			}
			else {
				m[x][y][1] = m[x][y][1] + 1;
				if (!check(x,y))
					m[x][y][1] = m[x][y][1] - 1;
			}
		}
		else { // ����
			if (type == 0) {
				if (m[x][y][0] > 0) {
					m[x][y][0] = m[x][y][0] - 1;
					if (!(check(x, y) && check(x, y + 1) && check(x - 1, y + 1)))
						m[x][y][0] = m[x][y][0] + 1;
				}
				if (m[x][y][1] > 0) {
					m[x][y][1] = m[x][y][1] - 1;
					if (!(check(x, y) && check(x-1, y) && check(x + 1, y)))
						m[x][y][1] = m[x][y][1] + 1;
				}
			}
			else {
				if (m[x][y][1] > 0) {
					m[x][y][1] = m[x][y][1] - 1;
					if (!check(x, y) && check(x - 1, y) && check(x + 1, y))
						m[x][y][1] = m[x][y][1] + 1;
				}
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (m[i][j][0] > 0) 				
				answer.push_back({ i, j, m[i][j][0] - 1});
			if ( m[i][j][1] > 0)
				answer.push_back({ i, j, m[i][j][1] });
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i][0] << "," << answer[i][1] << "," << answer[i][2] << endl;
	}
	
	return answer;
}

int main() {
	solution(5, { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} });
	//solution(5, { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} });
}
