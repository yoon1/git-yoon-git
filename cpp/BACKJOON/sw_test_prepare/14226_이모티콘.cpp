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
	queue<tuple<int, int, int>> q; // ȭ�� �̸�Ƽ��, Ŭ������, depth
	
	q.push({1,0,0}); // �ʱⰪ
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
		// 1. ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 ����
		// 3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ� ����
		if (emoticon > 0) {
			next = { emoticon, emoticon, depth + 1 }; if (isNew(make_pair(get<0>(next), get<1>(next)))) q.push(next);
			next = { emoticon - 1, clip, depth + 1 }; if (isNew(make_pair(get<0>(next), get<1>(next)))) q.push(next);
		}
		// 2. Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ��Ѵ�.
		if (clip > 0) {
			next = { emoticon + clip, clip , depth + 1 }; if (isNew(make_pair(get<0>(next), get<1>(next)))) q.push(next);
		}
	}
	return 0;
} 