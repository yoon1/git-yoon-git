#include <iostream>

using namespace std;

int N;
int main() 
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		printf("Case %d: %d\n", i, a + b);
	}
	return 0;
}