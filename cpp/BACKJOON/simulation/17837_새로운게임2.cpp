#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct pos{
	int y;
	int x;
}Pos;

typedef struct piece {
	Pos pos;
	int d;
}Piece;

int turn_count = 0;
int N, K; // ü������ ũ��, ���� ����
Piece pieces[11]; // ü���� ��ġ ����
vector <int> v[13][13]; // ü���ǿ����� ü���� id
int map[13][13]; // ü����
Pos dirs[5] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} }; // ��, ��, ��, �Ʒ�

bool isWallet(int y, int x){
	if (!(y > 0 && y <= N && x > 0 && x <= N))
		return true;
	if (map[y][x] == 2) // BLUE : ��
		return true;
	return false;
}
bool turn() { // ���� ĭ��  ���� 4�� �̻� ���̴� ���� true~
	for (int num = 1; num <= K; num++) { // ���� ��ȣ
		Pos cur = { pieces[num].pos.y, pieces[num].pos.x };
		int dir = pieces[num].d;
		Pos next = { cur.y + dirs[dir].y , cur.x + dirs[dir].x };
		if (isWallet(next.y, next.x)) {
			//dir ^= 1 << 0; // 0��° bit ������ ������ (0<->1, 2<->3);
			dir = dir % 2 == 0 ? dir - 1 : dir + 1;
			pieces[num].d = dir;
			next = { cur.y + dirs[dir].y , cur.x + dirs[dir].x };
			if (isWallet(next.y, next.x)) {
				continue;
			}
		}

		// temp�� ���
		vector<int>::iterator it = find(v[cur.y][cur.x].begin(), v[cur.y][cur.x].end(), num);
		vector<int> temp(it , v[cur.y][cur.x].end());
		if (v[cur.y][cur.x].size() == temp.size())
			v[cur.y][cur.x].clear();
		else
			v[cur.y][cur.x] = vector<int>(v[cur.y][cur.x].begin(), it);

		// ���࿡ �������̸� temp ������
		if (map[next.y][next.x] == 1) // RED 
			reverse(temp.begin(), temp.end());

		// ���� ��ġ�� 
		for (int i = 0; i < temp.size(); i++) {
			v[next.y][next.x].push_back(temp[i]);
			//pieces[temp[i]] = { next.y, next.x , pieces[temp[i]].d};
			pieces[temp[i]].pos.y = next.y;
			pieces[temp[i]].pos.x = next.x;
		}
		if (v[next.y][next.x].size() >= 4)
			return true;
	}	
	return false;
}
int main() {
	cin >> N >> K; //ü������ ũ��, ���� ����
	// input : ü������ ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	// input : ���� ����
	for (int i = 1; i <= K; i++)
	{
		Piece t;
		cin >> t.pos.y >> t.pos.x >> t.d;
		v[t.pos.y][t.pos.x].push_back(i); // ���� id�� dir�� ���� ����.
		pieces[i] = { t.pos.y, t.pos.x, t.d }; // ���� ��ġ
	}
	// 
	while (1) {
		if (turn_count > 1000 ) // Ż�� ���ǹ��� �����ұ�?.. ���� �ϴ� 1000�̻��̸� ���� ������.
		{
			cout << "-1";
			return 0;
		}
		turn_count++;
		if (turn()) {
			cout << turn_count;
			return 0;
		}
	}
	return 0;
}