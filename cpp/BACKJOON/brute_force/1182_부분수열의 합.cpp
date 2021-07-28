#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
queue<pair<pair<int, int>, bool>>q;

int bfs() {
	int idx = 0;
	int cnt = 0;
	q.push({{ 0,0 }, false });
	q.push({{ v[0],0 }, true });
	
	while(!q.empty()){
		int cur_num = q.front().first.first;
		int cur_pos = q.front().first.second;
		int cur_bool = q.front().second;
		q.pop();
		if ( cur_bool && cur_num == S)
			cnt++;

		if (cur_pos+1 >= N) continue; 
		q.push({ { cur_num ,cur_pos+1}, false});
		q.push({ { cur_num + v[cur_pos + 1], cur_pos + 1 }, true });
	}
	return cnt;
}
int main() {
	
	int cnt = 0;
	
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cout << bfs() << endl;
	return 0;

}

