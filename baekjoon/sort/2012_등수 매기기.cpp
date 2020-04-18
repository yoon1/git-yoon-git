#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> v;

int main()
{
	int N;
	long long total = 0;
	scanf_s("%d", &N);
	for(int i=0; i < N; i++) {
		int t;
		scanf_s("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= N; i++) {
		total = total + abs(v[i - 1] - i);
	}

	printf("%lld", total);

	return 0;
}

