#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	set<int> s;
	set<int>::iterator it;
	int N;
	int temp;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &temp);
		s.insert(temp);
	}

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &temp);
		printf("%d\n", s.find(temp) == s.end() ? 0 : 1);
	}

	return  0;
}