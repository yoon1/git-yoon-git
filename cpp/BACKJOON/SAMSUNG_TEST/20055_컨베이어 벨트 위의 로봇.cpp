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
	// 입력
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int t; 
		cin >> t;
		belt.push_back({false, t}); // 앞에 t를 넣음
	}
	//
	int count = 0;
	int turn = 0;
	while (count < K) { // K보다 커지면 종료
		turn++;
		
		

		/* 회전 */
		rotate(belt.rbegin(), belt.rbegin() + 1, belt.rend());

		// robot down
		belt[N - 1].robot = false;

		/* robot 올리기 */
		if(belt[0].d > 0) {
			belt[0].d--;
			belt[0].robot = true;
		}

		/* robot 이동 */
		for (int i = N-1 ; i > 1; i--) {
			if (belt[i - 1].robot && !belt[i].robot && belt[i].d > 0) { // 내구도 감소
				belt[i - 1].robot = false;
				belt[i].d--;
				belt[i].robot = true;
			}
		}

		// robot down
		belt[N-1].robot = false; 

		// 탐색
		count = 0;
		for (int i = 0; i < belt.size(); i++) {
			if ( belt[i].d <= 0) count++;
		}
	}
	cout << turn;
	return 0;
}