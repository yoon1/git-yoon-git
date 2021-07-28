// 보 설치하는 부분 개선 필요
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	bool map[101][101][2] = { false }; // map 
	// map[x][y]
	for (int i = 0; i < build_frame.size(); i++) {
		// x, y : 가로, 세로 좌표
		// a : 0 - 기둥, 1 - 보
		// b : 0 - 삭제, 1 - 설치
		int x = build_frame[i][0], y = build_frame[i][1], a = build_frame[i][2], b = build_frame[i][3];
		if (a == 0) // 기둥
		{
			// 1. 바닥 위 , 2. 보의 한쪽 끝, 3. 다른 기둥 위
			if (y == 0 || 
				((map[x-1][y][1] || map[x+1][y][1] ) && (!(map[x - 1][y][1] && map[x + 1][y][1]))) ||
				(map[x][y-1][0]) )
				map[x][y][0] = true;
		}
		else // 보
		{
			// 1. 한쪽 끝 기둥, 2. 양쪽 다른 보.
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