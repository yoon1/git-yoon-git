#include <iostream>
#include <algorithm>
#define INF 2e10

using namespace std;

long long A, B;
long long ret;

long long solution(long long n, long long cnt) {
	if (n > B) return INF;
	if (n == B) return cnt;
	return min(solution(n * 2, cnt + 1), solution((n * 10) + 1, cnt + 1));
}

int main() {

	cin >> A >> B;

	ret = solution(A,1);

	if (ret == INF) cout << -1;
	else cout << ret;
	return 0;
}