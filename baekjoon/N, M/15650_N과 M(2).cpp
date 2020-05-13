// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
// �� ������ ��������
// ���� 

/* 1 : iterator */ 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visited[9];
void dfs(int start, vector<int> v) {
	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int idx = start; idx <= N; idx++) {
		if ( !v.empty() && idx <= v.back())
			 	 continue;
		v.push_back(idx);
		dfs(start + 1, v);
		v.pop_back();
	}
}
int main() {
	vector<int> v;
	cin >> N >> M;
	dfs(1, v);
	return 0;
}


/* visited �迭 Ȱ�� */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visited[9];
vector<int> v;
void dfs(int start){
	if ( v.size() == M){
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int idx = start; idx <= N; idx++) {
		if (visited[idx]) continue;
		visited[idx] = true;
		v.push_back(idx);
		dfs(idx + 1);
		visited[idx] = false;
		v.pop_back();
	}
}
