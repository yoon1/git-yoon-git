#include <iostream>

using namespace std;

int arr[1001];
int N, M;
void print() {
	int total = 0;
	//for (int i = N; i <= M; i++)
	//	cout << arr[i] << endl;
	for (int i = N; i <= M; i++) 
		total += arr[i];
	cout << total;
}
int main() {
	int num = 1;
	cin >> N >> M;
	bool flag = true;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= i; j++) {
			arr[num++] = i;
			if (num > 1000) flag = false;
		}
		if (!flag) break;
	}
	print();
	return 0;
}