// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
// 고른 수열은 오름차순
// 조합 

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


/* visited 배열 활용 */
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
