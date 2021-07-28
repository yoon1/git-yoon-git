#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7]; // 방문처리
vector<int> a[8]; // 7개의 노드가 인접할 수 있게 만들어주었다.

void dfs(int x) {
	if (c[x]) return; //현재 노드를 방문했다면 return해서 함수를 끝낼 수 있게.
	c[x] = true; // 처음 방문하는 거면 방문 처리.
	cout << x << ' '; // 출력

	for (int i = 0; i < a[x].size(); i++) { // 계속해서 자기 노드를 반복적으로 수행..
		int y = a[x][i];
		dfs(y);
	}
}
int main() {
	a[1].push_back(2); // 1-2
	a[2].push_back(1); // 양방향이기 때문에 서로서로 연결.. (간선마다 2개씩 명령어가 들어가게 되는것)

	a[1].push_back(3); // 1-3
	a[3].push_back(1);

	a[2].push_back(3); // 2-3
	a[3].push_back(2);

	a[2].push_back(4); // 2-4
	a[4].push_back(2);

	a[2].push_back(5); // 2-5
	a[5].push_back(2);

	a[4].push_back(5); // 4-5
	a[5].push_back(4);

	a[3].push_back(6); // 3-6
	a[6].push_back(3);

	a[3].push_back(7); // 3-7
	a[7].push_back(3);

	a[6].push_back(7); // 6-7
	a[7].push_back(6);

	dfs(1); // 시작점은 1이라고 잡아주었습니다.
	return 0;
}