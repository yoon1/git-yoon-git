#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[15];
int cnt = 0;
int N;

bool isPromising(int n) {
	for (int i = 0; i < n; i++) {
		if ((a[i] == a[n]) || abs(a[n] - a[i]) == abs(n - i))
			return false;
	}
	return true;
}

void back_tracking(int idx) {
	if (idx == N) {
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			a[idx] = i;
			if (isPromising(idx)) 
				back_tracking(idx + 1);// �����ϴٸ� ��� Ž��(���ȣ��)
		}
	}
}
int main() {
	cin >> N;
	
	back_tracking(0);

	cout << cnt<< endl;
	return 0;
}