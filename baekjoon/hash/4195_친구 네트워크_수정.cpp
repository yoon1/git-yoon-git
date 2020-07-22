#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> name_id;
int relation[200002];
int id_cnt[200002];

int getParent(int x) {
	if (relation[x] == x) return relation[x];
	return relation[x] = getParent(relation[x]);
}
int merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		relation[b] = a;
		id_cnt[a] += id_cnt[b];
		id_cnt[b] = 1;
		return id_cnt[a];
	}
	else if (a > b) {
		relation[a] = b;
		id_cnt[b] += id_cnt[a];
		id_cnt[a] = 1;
		return id_cnt[b];
	}
	return id_cnt[b];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N;
		int idx = 0;
		cin >> N;
		// √ ±‚»≠
		name_id.clear();
		for (int i = 0; i < 2 * N; i++) {
			relation[i] = i;
			id_cnt[i] = 1;
		}
		
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			if (!name_id.count(a)) name_id[a] = idx++;
			if (!name_id.count(b)) name_id[b] = idx++;

			cout << merge(name_id[a], name_id[b]) << "\n";
		}
	}
	return 0;
}