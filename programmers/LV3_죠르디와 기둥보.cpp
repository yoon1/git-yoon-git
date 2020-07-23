// �� ��ġ�ϴ� �κ� ���� �ʿ�
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	bool map[101][101][2] = { false }; // map 
	// map[x][y]
	for (int i = 0; i < build_frame.size(); i++) {
		// x, y : ����, ���� ��ǥ
		// a : 0 - ���, 1 - ��
		// b : 0 - ����, 1 - ��ġ
		int x = build_frame[i][0], y = build_frame[i][1], a = build_frame[i][2], b = build_frame[i][3];
		if (a == 0) // ���
		{
			// 1. �ٴ� �� , 2. ���� ���� ��, 3. �ٸ� ��� ��
			if (y == 0 || 
				((map[x-1][y][1] || map[x+1][y][1] ) && (!(map[x - 1][y][1] && map[x + 1][y][1]))) ||
				(map[x][y-1][0]) )
				map[x][y][0] = true;
		}
		else // ��
		{
			// 1. ���� �� ���, 2. ���� �ٸ� ��.
			if (map[x - 1][y][1] && map[x + 1][y][1])
				map[x][y][1] = true;
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (map[i][j][0])
				answer.push_back({ i,j,0 });
			if (map[i][j][1])
				answer.push_back({ i,j,1 });
		}
	}
	return answer;
}

int main() {
	solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}});

	return 0;
}