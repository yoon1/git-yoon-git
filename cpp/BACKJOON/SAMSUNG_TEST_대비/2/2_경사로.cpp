#include <iostream>
#define MAX 100

using namespace std;

int N, L, result;
int map[MAX][MAX];

void go(int i, bool flag) { // row ��ȣ Ȥ�� col ��ȣ
	int cnt = 1;	
	for (int j = 0; j < N - 1; j++) {
		int d = flag ? (map[i][j + 1] - map[i][j]) : (map[j+1][i] - map[j][i]); // ���� 
		if (d == 0) // ���̰� 0�̸� count++
			cnt++;
		else if (d == 1 && cnt >= L) // �� �������ٸ�, �׸��� count�� ������ L�̶�� 
			cnt = 1;
		else if (d == -1 && cnt >= 0 ) // �� �������ٸ�
			cnt = -L + 1;
		else return; // 2ĭ �̻� ���̳�
	}
	if (cnt >= 0) result += 1; // ok
}
int main() {
	cin >> N >> L;
	for(int i=0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++) {
		go(i, true); 
		go(i, false);
	}


	cout << result;
	return 0;
}