#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int total = 0;
	for (int i = 0; i <= N; i++) 
		for (int j = 0; j <= i; j++) 
			total += (i+j);
	cout << total;
	return 0;
}