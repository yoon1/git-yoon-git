#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; // ���� ����(���� 6��)
int d[7]; // �ּ� ���

// O(N*logN) �������
// O(N*N
void dijkstra(int start) {
	d[start] = 0; // �ڱ� �ڽ����� ���� �� 0.
	priority_queue<pair<int, int> > pq; // �� ����.
	pq.push(make_pair(start, 0)); // (���, ��)
	// ����� ������� ó���ϹǷ� ť ���.
	while (!pq.empty()) { // pq�� ������� �ʴٸ� ����ؼ� �ϳ��� ������ ��.
		int current = pq.top().first; // ���� ���� ����� ��� ��� ������ �������.
		// ª�� ���� ���� ������ �ϱ� ���� ����ȭ(-) �մϴ�. (�ֳĸ� C++�� pq���ִ� ���̶�..)
		int distance = -pq.top().second;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��쿡�� skip
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// ���õ� ����� ���� ���
			int next = a[current][i].first;
			cout << current << "," << next << endl;
			// ���õ� ��带 ���� ���� ���ļ� ���� ���
			int nextDistance = distance + a[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü.
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance)); // ���Ӱ� ���ŵ� ��.
			}
		}
	}
}

int main() {
	// �Ȱ��� ���� max
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	// graph
	a[1].push_back(make_pair(2, 2)); 
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	// ��� ���

	for (int i = 1; i <= number; i++) {
		cout << d[i] << " ";
	}

	return 0;
}
