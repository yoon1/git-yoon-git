#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

typedef struct dir {
	int y;
	int x;
}Dir;

int result = 9999999;
int map[8][8] = { 0 };
int t_map[8][8] = { 0 };
bool cctv_dir[8][8][4];
vector<int> angle;
vector<Dir> cctvs;
Dir dir[4] = { {-1,0},{0,1},{1,0},{0,-1} }; // ºÏ, µ¿, ³², ¼­
int N, M;

int getEmpty(void) {
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (t_map[i][j] == 0)
				count++;
	return count;
}

void dfs() {
	if (angle.size() == cctvs.size()) {
		for (int i = 0; i < angle.size(); i++) {
			Dir cur = cctvs[i];
			for (int j = 0; j < 4; j++) {
				if ( cctv_dir[cur.y][cur.x][j] ) {
					Dir next;
					next.y = cur.y + dir[(angle[i] + j) % 4].y;
					next.x = cur.x + dir[(angle[i] + j) % 4].x;
					while(1){
						if (t_map[next.y][next.x] == 6)
							break;
						if (!(0 <= next.y && next.y < N && 0 <= next.x && next.x < M))
							break;
						if (t_map[next.y][next.x] == 0)
							t_map[next.y][next.x] = -1;
						next.y += dir[(angle[i] + j) % 4].y;
						next.x += dir[(angle[i] + j) % 4].x;
					} 
				}
			}
		}
		result = min(result, getEmpty());
		memcpy(t_map, map, sizeof(t_map));
		return;
	}

	for (int i = 0; i < 4; i++) {
		angle.push_back(i);
		dfs();
		angle.pop_back();
	}
}

int main() 
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5){
				Dir t = Dir({ i,j });
				cctvs.push_back(t);
				switch( map[i][j] ) {
					case 1 :
						cctv_dir[i][j][0] = true;
						break;
					case 2:
						cctv_dir[i][j][0] = true;
						cctv_dir[i][j][2] = true;
						break;
					case 3 :
						cctv_dir[i][j][0] = true;
						cctv_dir[i][j][1] = true;
						break;
					case 4 :
						cctv_dir[i][j][0] = true;
						cctv_dir[i][j][1] = true;
						cctv_dir[i][j][2] = true;
						break;
					case 5 :
						cctv_dir[i][j][0] = true;
						cctv_dir[i][j][1] = true;
						cctv_dir[i][j][2] = true;
						cctv_dir[i][j][3] = true;
						break;
				}
			}
		}
	}
	memcpy(t_map, map, sizeof(t_map));
	dfs();

	cout << result << endl;
	return 0;
}