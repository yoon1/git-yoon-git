#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 987654321;

using namespace std;

// start를 중심으로 start에서 weak 까지는 그냥 집어넣고 그 다음부터는 n을 넣어서 start list를 새로 만든다.
// 10, 13, 17, 18 같은 식으로..
vector<int> changeStartIdx(vector<int> weak, int start, int n) {
	if (start == 0) return weak;
	vector<int> _ret;
	for (int i = start; i < weak.size(); i++) 
		_ret.push_back(weak[i]);
	for (int i = 0; i < start; i++) 
		_ret.push_back(weak[i] + n);
	return _ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int ret = INF; // 최솟값 ret를 찾는다.
	sort(dist.begin(), dist.end()); // dist는 정렬되었다는 조건이 없으므로 오름차순 정렬
	// brute force
	do {
		for (int j = 0; j < weak.size(); j++) { // 
			vector<int> _weak = changeStartIdx(weak, j, n);
			int idx = 0; // 친구 수
			int cur = _weak[0] + dist[idx]; // cover
			bool flag = true;

			//pivot algorithm
			for (int i = 1; i < _weak.size(); i++) {
				if (_weak[i] > cur) {
					if (++idx == dist.size()) { // 더이상 친구 없으면?
						flag = false;
						break;
					}
					cur = _weak[i] + dist[idx]; // dist를 더한다.
				}
			}
			if (flag)
				ret = min(ret, idx + 1);
		}
	} while (next_permutation(dist.begin(), dist.end()));
	if (ret == INF) return -1;
	return ret;
}

int main() {
	solution(12, { 1,5,6,10 }, { 1,2,3,4, });

	return 0;
}