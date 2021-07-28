#include <iostream>
#define MAX 1001


using namespace std;

int arr[MAX];
int lis[MAX];
int dp[MAX];
int N;
int max_len;

void Print(int idx) {
	if (idx == dp[idx]) {
		cout << arr[idx] << " ";
		return;
	}
	Print(dp[idx]);
	cout << arr[idx] << " ";
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = i, lis[i] = 1;
		for (int j = 0; j < i; j++) 
			if (arr[j] < arr[i])
				if ( lis[i] < lis[j] + 1)
					lis[i] = lis[j] + 1, dp[i] = j;
		
		if (lis[i] > lis[max_len]) max_len = i;
	}
	cout << lis[max_len] << "\n";

	Print(max_len);
	return 0;
}