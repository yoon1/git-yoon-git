#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N;
	deque<int> dq;
	cin >> N;
	int count = 0;
	
	int a = (N / 10);
	int b = (N % 10);
	while (1) {
		int c = ((a + b) % 10);
		a = b;
		b = c;
		count++;
		if (a * 10 + b == N) {
			break;
		}
	}
	cout << count << endl;
	return 0;
 }