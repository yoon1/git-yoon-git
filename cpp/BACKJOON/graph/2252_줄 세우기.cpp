#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[32002];
int N, M;

void topologicalSort(vector<int> &cntOfLink) {
	queue<int> q;
	// �ʱ� : ���� ������ ���� �ʴ� ������ queue�� ����
	for (int i = 1; i <= N ; i++) 
		if (cntOfLink[i] == 0) 	// �ش� ������ ������ ���� 0�̸�?
			q.push(i);
		
	// ������ �� ��ŭ �ݺ�
	for (int i = 0; i < N; i++) {
		// 1. queue���� ���� ����
		int v = q.front(); 
		q.pop();
		cout << v << " "; // ���� ���
		
		// 2. ������ ����� ��� ������ ���ؼ�
		for (int nextV : graph[v]) {
			// 2-1 ������ �� ����
			cntOfLink[nextV]--; 

			// 2-2 ���� ������ ���� �ʴ� ������ queue�� ����
			if (cntOfLink[nextV] == 0) // �ش� ������ ������ ���� 0�̸�
				q.push(nextV);
		}
	}
}

int main() {
	cin >> N >> M;
	// ������ ���� ���� �迭
	vector<int> cntOfLink(N+1,0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		cntOfLink[b]++;
	}
	topologicalSort(cntOfLink);
	return 0;

}