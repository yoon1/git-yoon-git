#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 987654321;

using namespace std;

// start�� �߽����� start���� weak ������ �׳� ����ְ� �� �������ʹ� n�� �־ start list�� ���� �����.
// 10, 13, 17, 18 ���� ������..
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
	int ret = INF; // �ּڰ� ret�� ã�´�.
	sort(dist.begin(), dist.end()); // dist�� ���ĵǾ��ٴ� ������ �����Ƿ� �������� ����
	// brute force
	do {
		for (int j = 0; j < weak.size(); j++) { // 
			vector<int> _weak = changeStartIdx(weak, j, n);
			int idx = 0; // ģ�� ��
			int cur = _weak[0] + dist[idx]; // cover
			bool flag = true;

			//pivot algorithm
			for (int i = 1; i < _weak.size(); i++) {
				if (_weak[i] > cur) {
					if (++idx == dist.size()) { // ���̻� ģ�� ������?
						flag = false;
						break;
					}
					cur = _weak[i] + dist[idx]; // dist�� ���Ѵ�.
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