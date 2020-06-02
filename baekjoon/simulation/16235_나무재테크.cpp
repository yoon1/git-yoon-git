#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct pos { // 좌표
	int y; 	int x;
}Pos;

int N, M, K;
int A[11][11];   // 양분
int map[11][11]; // 현재상태
Pos dirs[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }; // 인접한 칸
vector<int> tree[11][11]; // 각 칸의 나무의 나이 (id까진 필요 없을듯)

int treeCount() {
	int total = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			total += tree[y][x].size();
		}
	}
	return total;
}

void fall_winter() { // 가을 : 번식
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int size = tree[y][x].size();
			for (int k = 0; k < size; k++) {  // 먼저 sorting
				if (tree[y][x][k] % 5 == 0) { //5의 배수면?
					for (int i = 0; i < 8; i++) {
						int ny = y + dirs[i].y; int nx = x + dirs[i].x;
						if (ny > 0 && ny <= N && nx > 0 && nx <= N)
							tree[ny][nx].push_back(1);
					}
				}
			}
			map[y][x] += A[y][x];
		}
	}
}
void spring_summer() { // 봄 : 양분 소모
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tree[y][x].empty()) continue;
			vector<int> _tree;
			int death = 0;
			sort(tree[y][x].begin(), tree[y][x].end()); // 나이순으로 정렬 (나이가 어린순으로)
			int size = tree[y][x].size();
			for (int i = 0; i < size; i++) {
				int age = tree[y][x][i];
				if (map[y][x] - age >= 0) {// 양분이 충분하면 ㄱㅊ
					map[y][x] -= age;
					_tree.push_back(age + 1);
				}
				else {// 양분이 충분하지 못하면 남은 나이 많은 나무들은 양분 못먹고 죽음
					death += ( age / 2);
					//map[y][x] += (age / 2); // 양분 충전
				}
			}
			tree[y][x].clear();
			tree[y][x] = _tree;
			map[y][x] += death;
		}
	}
}
int main() {
	cin >> N >> M >> K; // A 크기 N, 나무 갯수 M개 , K년
	 // 1. 양분 INFO INPUT
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> A[y][x]; // i,j 입력
			map[y][x] = 5;
		}
	}
	// 2. 나무 INFO INPUT
	for (int i = 0; i < M; i++) {
		int y, x, age;
		cin >> y >> x >> age;
		tree[y][x].push_back(age);
	}
	// 3. 4계절 나기
	for (int i = 0; i < K; i++) { // K년 후?
		spring_summer();
		fall_winter();
	}
	cout << treeCount();
	return 0;
}