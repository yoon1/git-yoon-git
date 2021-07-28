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

bool operator < (State a, State b) { // ���� ���� �տ� ������ operator�� ������ִ� �۾��̴�.
	if (a.gas < b.gas) return true; // �ִ� �Ÿ� ª��(���ᰡ ���� ���)
	if (a.gas == b.gas) {  
		if (a.y > b.y) return true; // �� ��ȣ ����
		if (a.y == b.y && a.x > b.x) return true; // �� ��ȣ ����
	}
	return false;
}

bool go(pair<int, int> start) { // �°� �¿��ֱ�~~! 
	pair<int, int> cd = dest[start];
	
	queue<pair<State, int>> q;
	q.push({ {start.first, start.second, gas} , 0 });

	bool visited[MAX][MAX] = { false, };
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int cy = q.front().first.y;
		int cx = q.front().first.x;
		int cg = q.front().first.gas;
		int moveCnt = q.front().second; // �̵��Ÿ�

		q.pop();

		if (cg == -1) return false; // ���� x

		if (cy == cd.first && cx == cd.second) { // ������ ���� -> true
			gas = cg + moveCnt * 2; // ����� �̵� �Ÿ��� 2��
			return true;
		}

		for (int k = 0; k < 4; k++) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue; // �� ��
			
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
	cin >> N >> M >> gas; // N, M�� ������, �ʱ� ������ ��
	
	for (int i = 0; i < N; i++) // ������ Ȱ�� ����
		for (int j = 0; j < N; j++) 
			cin >> road[i][j]; // 0�� ��ĭ, 1�� ��


	pair<int, int> start; // ������ ���� ��ġ
	cin >> start.first >> start.second;
	start.first--; start.second--;

	for (int i = 0; i < M; i++) {
		int y, x, y2, x2;
		cin >> y >> x >> y2 >> x2;  // �°��� ��� ��ǥ(y,x) : key, ������ ��ǥ(y2, x2) : value
		y--, x--, y2--, x2--;
		dest[{y, x}] = { y2, x2 };
	}
	/* INPUT */


	while (1) { // �ýð� �����̴°ſ���
		priority_queue<State> pq; // ���� ��ġ���� �ִܰŸ��� ���� ª��, �� ��ȣ�� ���� ���� �°�, �������̸� �� �� ��ȣ�� ���� ���� �°�
		pq.push({ start.first, start.second, gas }); // �ý��� ���� ��ġ�� �ִ´�.

		bool visited[MAX][MAX] = { false, }; // �湮�� ������
		visited[start.first][start.second] = true; 

		bool flag = false;

		while (!pq.empty()) { // �մ� ã��
			int cy = pq.top().y; 
			int cx = pq.top().x;
			int cg = pq.top().gas;
			pq.pop();

			if (cg == -1) // ���ᰡ ������? 
				break;

			if (dest.count({ cy, cx })) // ���� �մ��� �ִ��� Ȯ��
			{
				// ������ ��ǥ�� -1�� �ƴϾ�� ��
				start = { cy,cx }; // ������? ã�Ҵٰ� ǥ����
				flag = true;
				gas = cg;
				break;
			}
			
			// ������? ��� �ýð� �̵���~~!
			for (int k = 0; k < 4; k++) {
				int ny = cy + dy[k];
				int nx = cx + dx[k];

				if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue; // �� ��

				if (visited[ny][nx] || road[ny][nx]) continue; // �̹� �湮�� �� �ְų� ��

				visited[ny][nx] = true; // �湮

				pq.push({ ny, nx, cg - 1 }); // ���� ����
			}
		}

		if ( flag == false) { // ���ᰡ �ٴڳ���
			cout << -1 << "\n";
			return 0;
		}

		if (go(start) == false) { // ��� �մ��� �̵���Ű�� ��������?
			cout << -1 << "\n";
			return 0;
		}

		if (--M == 0) { // �°� �� 0��? --> good 
			cout << gas << "\n"; // ���� ���� ���
			return 0;
		}

		pair<int, int> temp = start;
		start = dest[{start.first, start.second}];
		//dest[{temp.first, temp.second}] = { -1,-1 }; // ������ ���� -1�� ������ش�. (�������� map���� ������ ���������
		dest.erase(temp); // �� ����~
	}

	return 0;
}