#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> s;
char map[5][5];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int dirs[5] = { 0 };

void makeNum() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string str;
			int y = i;
			int x = j;
			str += map[y][x];
			bool flag = true;
			for (int i = 0; i < 5; i++) {
				y += dy[dirs[i]];
				x += dx[dirs[i]];
				if (!(y >= 0 && x >= 0 && y < 5 && x < 5)) {
					flag = false;
					break;
				}
				str += map[y][x];
			}
			if (flag) {
				s.insert(str);
			}
		}
	}
}
void go(int cnt) {
	if (cnt == 5) {
		/* for (int i = 0; i < 4; i++) 
			cout << dirs[i] << " ";
		cout << "\n"; */
		makeNum();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dirs[cnt] = i;
		go(cnt + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	go(0);
	cout << s.size() << endl;
	return 0;
}