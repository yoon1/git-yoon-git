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
int N, K; // 체스판의 크기, 말의 개수
Piece pieces[11]; // 체스말 위치 정보
vector <int> v[13][13]; // 체스판에서의 체스말 id
int map[13][13]; // 체스판
Pos dirs[5] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} }; // 오, 왼, 위, 아래

bool isWallet(int y, int x){
	if (!(y > 0 && y <= N && x > 0 && x <= N))
		return true;
	if (map[y][x] == 2) // BLUE : 벽
		return true;
	return false;
}
bool turn() { // 같은 칸에  말이 4개 이상 쌓이는 순간 true~
	for (int num = 1; num <= K; num++) { // 말의 번호
		Pos cur = { pieces[num].pos.y, pieces[num].pos.x };
		int dir = pieces[num].d;
		Pos next = { cur.y + dirs[dir].y , cur.x + dirs[dir].x };
		if (isWallet(next.y, next.x)) {
			//dir ^= 1 << 0; // 0번째 bit 연산자 뒤집기 (0<->1, 2<->3);
			dir = dir % 2 == 0 ? dir - 1 : dir + 1;
			pieces[num].d = dir;
			next = { cur.y + dirs[dir].y , cur.x + dirs[dir].x };
			if (isWallet(next.y, next.x)) {
				continue;
			}
		}

		// temp에 담기
		vector<int>::iterator it = find(v[cur.y][cur.x].begin(), v[cur.y][cur.x].end(), num);
		vector<int> temp(it , v[cur.y][cur.x].end());
		if (v[cur.y][cur.x].size() == temp.size())
			v[cur.y][cur.x].clear();
		else
			v[cur.y][cur.x] = vector<int>(v[cur.y][cur.x].begin(), it);

		// 만약에 빨간색이면 temp 뒤집기
		if (map[next.y][next.x] == 1) // RED 
			reverse(temp.begin(), temp.end());

		// 다음 위치에 
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
	cin >> N >> K; //체스판의 크기, 말의 개수
	// input : 체스판의 정보
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	// input : 말의 정보
	for (int i = 1; i <= K; i++)
	{
		Piece t;
		cin >> t.pos.y >> t.pos.x >> t.d;
		v[t.pos.y][t.pos.x].push_back(i); // 말의 id랑 dir를 갖고 있음.
		pieces[i] = { t.pos.y, t.pos.x, t.d }; // 말의 위치
	}
	// 
	while (1) {
		if (turn_count > 1000 ) // 탈출 조건문은 뭘로할까?.. 값이 일단 1000이상이면 게임 종료임.
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