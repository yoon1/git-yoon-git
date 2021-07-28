#include <iostream>
#define TWO 2
using namespace std;

bool sosu[1000001] = { false };
int M, N;

int main() {
	cin >> M >> N;
	for (int i = TWO; i <= N; i++)
		for (int j = TWO; i*j <= N; j++)
			sosu[i*j] = true;

	for (int i = (M < TWO ? TWO : M); i <= N; i++)
		if (!sosu[i]) printf("%d\n", i);

	return 0;
}