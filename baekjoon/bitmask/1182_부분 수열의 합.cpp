#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N = 0, S = 0;
	// input
	scanf("%d %d", &N, &S);
	vector<int> v(N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &v[i]);
	
	int count = 0;
	for (int i = 1; i < (1 << N); i++) { 
		int sum = 0;
		for (int j = 0; j < N; j++)
			if (i & (1 << j)) 
				sum += v[j]; 
		if (sum == S) count++;
	}
	printf("%d", count);
	return 0;
}