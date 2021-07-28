#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct pos { // ��ǥ
	int y; 	int x;
}Pos;

int N, M, K;
int A[11][11];   // ���
int map[11][11]; // �������
Pos dirs[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }; // ������ ĭ
vector<int> tree[11][11]; // �� ĭ�� ������ ���� (id���� �ʿ� ������)

int treeCount() {
	int total = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			total += tree[y][x].size();
		}
	}
	return total;
}

void fall_winter() { // ���� : ����
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int size = tree[y][x].size();
			for (int k = 0; k < size; k++) {  // ���� sorting
				if (tree[y][x][k] % 5 == 0) { //5�� �����?
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
void spring_summer() { // �� : ��� �Ҹ�
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tree[y][x].empty()) continue;
			vector<int> _tree;
			int death = 0;
			sort(tree[y][x].begin(), tree[y][x].end()); // ���̼����� ���� (���̰� �������)
			int size = tree[y][x].size();
			for (int i = 0; i < size; i++) {
				int age = tree[y][x][i];
				if (map[y][x] - age >= 0) {// ����� ����ϸ� ����
					map[y][x] -= age;
					_tree.push_back(age + 1);
				}
				else {// ����� ������� ���ϸ� ���� ���� ���� �������� ��� ���԰� ����
					death += ( age / 2);
					//map[y][x] += (age / 2); // ��� ����
				}
			}
			tree[y][x].clear();
			tree[y][x] = _tree;
			map[y][x] += death;
		}
	}
}
int main() {
	cin >> N >> M >> K; // A ũ�� N, ���� ���� M�� , K��
	 // 1. ��� INFO INPUT
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> A[y][x]; // i,j �Է�
			map[y][x] = 5;
		}
	}
	// 2. ���� INFO INPUT
	for (int i = 0; i < M; i++) {
		int y, x, age;
		cin >> y >> x >> age;
		tree[y][x].push_back(age);
	}
	// 3. 4���� ����
	for (int i = 0; i < K; i++) { // K�� ��?
		spring_summer();
		fall_winter();
	}
	cout << treeCount();
	return 0;
}