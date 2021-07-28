#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;
	int i = 1;
	int time = 0;
	while (N > 0) {
		if (i > N) i = 1;
		N -= i++;
		time++;
	}
	cout << time;
	return 0;
}
