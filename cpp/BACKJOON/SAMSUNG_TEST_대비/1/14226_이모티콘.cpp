#include <iostream>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

int n;
set<pair<int, int>> s;

bool isNew(pair<int, int> t) {
	if (s.find(t) == s.end()) {
		s.insert(t);
		return true;
	}
	return false;
}
int main() {
	scanf("%d", &n);
	queue<tuple<int, int, int>> q; // 화면 이모티콘, 클립보드, depth
	
	q.push({1,0,0}); // 초기값
	while (!q.empty()) {
		int emoticon, clip, depth;
		tie(emoticon, clip, depth) = q.front();
		q.pop();
		cout << emoticon << "," << clip << "," << depth << endl;
		if (emoticon == n) {
			cout << depth << endl;
			return 0;
		}
		tuple<int, int, int> next;
		// 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
		// 3. 화면에 있는 이모티콘 중 하나 삭제
		if (emoticon > 0) {
			next = { emoticon, emoticon, depth + 1 }; if (isNew(make_pair(get<0>(next), get<1>(next)))) q.push(next);
			next = { emoticon - 1, clip, depth + 1 }; if (isNew(make_pair(get<0>(next), get<1>(next)))) q.push(next);
		}
		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기한다.
		if (clip > 0) {
			next = { emoticon + clip, clip , depth + 1 }; if (isNew(make_pair(get<0>(next), get<1>(next)))) q.push(next);
		}
	}
	return 0;
} 