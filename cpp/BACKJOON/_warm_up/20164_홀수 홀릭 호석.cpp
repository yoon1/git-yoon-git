#include <iostream>
#include <algorithm>
#include <math.h>
#define INF 2e8

using namespace std;

int min_val = INF;
int max_val = 0;

// ���� ���ϱ�
int num_split(int num, int len, int left, int right) {
	int a = pow(10, len - left); 
	int b = pow(10, len - right - 1);

	num %= a;
	num /= b;

	return num;
}

// ���� ����
int num_len(int num) {
	int ret;
	if (num < 0) num = -num;
	for (ret = 0; num > 0; num /= 10, ret++);
	return ret;
}

// Ȧ�� ī��Ʈ
int	odd_count(int N) { 
	int ret = 0;
	while(N > 0) {
		ret += (N % 10) % 2 == 1 ? 1 : 0 ;
		N /= 10;
	}
	return ret;
}

void backtracking(int N, int pre) {
	// 1. Ȧ���� ������ ���̿� ���´�.
	int len = num_len(N);
	int cur = pre + odd_count(N); // Ȧ���� ī��Ʈ�Ѵ�.

	if (N < 1) return;
	//1���� ? ����
	if (N < 10) {
		max_val = max(max_val, cur);
		min_val = min(min_val, cur);
		return;
	} 
	// 2�� �̻��̸�? ������ �ɰ���
	else if (N < 100) { 
		int snum = (N / 10) + (N % 10);
		backtracking(snum, cur);
	}
	else 
	// 3�ڸ� �̻��̸�? 3���� �ɰ���
	{ 
		for (int i = 0; i < len-2; i++) {
			// 3���
			for (int j = i+1; j < len-1; j++) {
				int left_num = num_split(N, len, 0, i);
				int mid_num = num_split(N, len, i+1, j);
				int right_num = num_split(N, len, j+1, len-1);
				int snum = left_num + mid_num + right_num;
				backtracking(snum, cur);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	backtracking(N,0);
	cout << min_val << " " << max_val;
	return 0;
}