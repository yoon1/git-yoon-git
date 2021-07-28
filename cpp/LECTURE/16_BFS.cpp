#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; // 방문 처리를 위해 만든 배열. checked의 약자입니다. 방문했다는 걸 표시함!
vector<int> a[8]; // 각 노드의 인덱스가 1부터 처리될 수 있도록 8로 만들었어요~

void bfs(int start) { 
	queue<int> q; 
	q.push(start); // 맨 첨에는 queue의 시작점을 넣어줍니다.
	c[start] = true; 
	while (!q.empty()) { // queue가 빌떄까지 반복.
		int x = q.front(); // queue에서 하나 꺼내서 변수 x에 넣음.
		q.pop(); // x출력
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) { // i는 인접한 노드와 하나씩 방문을 하면서 
			int y = a[x][i];
			if (!c[y]) { // 방문을 한 상태? 라면 무시하고.
				q.push(y); // 아니면 이렇게 queue에 담아주면 됩니다.
				c[y] = true; // 방문처리.
			}
		}
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

	bfs(1); // 시작점은 1이라고 잡아주었습니다.
	
	return 0;
}