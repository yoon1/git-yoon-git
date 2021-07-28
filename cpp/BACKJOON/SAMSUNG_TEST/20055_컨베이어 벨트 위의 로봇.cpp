#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

struct square{
	bool robot;
	int d;
};

int N, K;
deque<square> belt;

int main() {
	// �Է�
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int t; 
		cin >> t;
		belt.push_back({false, t}); // �տ� t�� ����
	}
	//
	int count = 0;
	int turn = 0;
	while (count < K) { // K���� Ŀ���� ����
		turn++;
		
		

		/* ȸ�� */
		rotate(belt.rbegin(), belt.rbegin() + 1, belt.rend());

		// robot down
		belt[N - 1].robot = false;

		/* robot �ø��� */
		if(belt[0].d > 0) {
			belt[0].d--;
			belt[0].robot = true;
		}

		/* robot �̵� */
		for (int i = N-1 ; i > 1; i--) {
			if (belt[i - 1].robot && !belt[i].robot && belt[i].d > 0) { // ������ ����
				belt[i - 1].robot = false;
				belt[i].d--;
				belt[i].robot = true;
			}
		}

		// robot down
		belt[N-1].robot = false; 

		// Ž��
		count = 0;
		for (int i = 0; i < belt.size(); i++) {
			if ( belt[i].d <= 0) count++;
		}
	}
	cout << turn;
	return 0;
}