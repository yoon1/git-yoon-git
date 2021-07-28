#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int MAX = 20;

struct State {
	int y, x, gas;
};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int N, M, gas;
map<pair<int, int>, pair<int, int>> dest;
int road[MAX][MAX];

bool operator < (State a, State b) { // 뭐가 제일 앞에 올지를 operator로 만들어주는 작업이다.
	if (a.gas < b.gas) return true; // 최단 거리 짧은(연료가 적게 드는)
	if (a.gas == b.gas) {  
		if (a.y > b.y) return true; // 행 번호 작은
		if (a.y == b.y && a.x > b.x) return true; // 열 번호 작은
	}
	return false;
}

bool go(pair<int, int> start) { // 승객 태워주기~~! 
	pair<int, int> cd = dest[start];
	
	queue<pair<State, int>> q;
	q.push({ {start.first, start.second, gas} , 0 });

	bool visited[MAX][MAX] = { false, };
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int cy = q.front().first.y;
		int cx = q.front().first.x;
		int cg = q.front().first.gas;
		int moveCnt = q.front().second; // 이동거리

		q.pop();

		if (cg == -1) return false; // 연료 x

		if (cy == cd.first && cx == cd.second) { // 목적지 도착 -> true
			gas = cg + moveCnt * 2; // 연료는 이동 거리의 2배
			return true;
		}

		for (int k = 0; k < 4; k++) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue; // 맵 밖
			
			if (visited[ny][nx] || road[ny][nx]) continue;

			visited[ny][nx] = true;

			q.push({ {ny, nx, cg - 1} , moveCnt + 1 });
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/* INPUT */
	cin >> N >> M >> gas; // N, M의 사이즈, 초기 연료의 양
	
	for (int i = 0; i < N; i++) // 백준의 활동 영역
		for (int j = 0; j < N; j++) 
			cin >> road[i][j]; // 0은 빈칸, 1은 벽


	pair<int, int> start; // 백준의 시작 위치
	cin >> start.first >> start.second;
	start.first--; start.second--;

	for (int i = 0; i < M; i++) {
		int y, x, y2, x2;
		cin >> y >> x >> y2 >> x2;  // 승객의 출발 좌표(y,x) : key, 목적지 좌표(y2, x2) : value
		y--, x--, y2--, x2--;
		dest[{y, x}] = { y2, x2 };
	}
	/* INPUT */


	while (1) { // 택시가 움직이는거에용
		priority_queue<State> pq; // 현재 위치에서 최단거리가 가장 짧고, 행 번호가 가장 작은 승객, 여러명이면 그 중 번호가 가장 작은 승객
		pq.push({ start.first, start.second, gas }); // 택시의 현재 위치를 넣는다.

		bool visited[MAX][MAX] = { false, }; // 방문한 곳인지
		visited[start.first][start.second] = true; 

		bool flag = false;

		while (!pq.empty()) { // 손님 찾기
			int cy = pq.top().y; 
			int cx = pq.top().x;
			int cg = pq.top().gas;
			pq.pop();

			if (cg == -1) // 연료가 없으면? 
				break;

			if (dest.count({ cy, cx })) // 여기 손님이 있는지 확인
			{
				// 목적지 좌표가 -1이 아니어야 함
				start = { cy,cx }; // 있으면? 찾았다고 표시함
				flag = true;
				gas = cg;
				break;
			}
			
			// 없으면? 계속 택시가 이동함~~!
			for (int k = 0; k < 4; k++) {
				int ny = cy + dy[k];
				int nx = cx + dx[k];

				if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue; // 맵 밖

				if (visited[ny][nx] || road[ny][nx]) continue; // 이미 방문한 적 있거나 벽

				visited[ny][nx] = true; // 방문

				pq.push({ ny, nx, cg - 1 }); // 연료 감소
			}
		}

		if ( flag == false) { // 연료가 바닥났음
			cout << -1 << "\n";
			return 0;
		}

		if (go(start) == false) { // 모든 손님을 이동시키지 못했으면?
			cout << -1 << "\n";
			return 0;
		}

		if (--M == 0) { // 승객 수 0명? --> good 
			cout << gas << "\n"; // 남은 연료 출력
			return 0;
		}

		pair<int, int> temp = start;
		start = dest[{start.first, start.second}];
		//dest[{temp.first, temp.second}] = { -1,-1 }; // 도착한 곳은 -1로 만들어준다. (내생각엔 map에서 날려도 상관없을듯
		dest.erase(temp); // 고객 제거~
	}

	return 0;
}