#include <iostream>

using namespace std;

int N, B, C;
int A[1000000];
int main() {
	scanf("%d", &N);
	long long answer = 0;
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] = (A[i] - B < 0) ?  0 : A[i] - B;
		answer += ((A[i] % C == 0) ? A[i] / C : (A[i] / C) + 1) + 1;
	}
	cout << answer;
	return 0;
}