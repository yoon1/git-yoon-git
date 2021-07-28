#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int temp;
	map<int, int> m;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &temp);
		if (m.find(temp) != m.end()) m[temp]++;	
		else m[temp] = 1;
	}

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &temp);
		printf("%d ", m.find(temp) == m.end() ? 0 : m[temp]);
	}
	
	return 0;
}