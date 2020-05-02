#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

// 12시 방향 : 0
//  3시 방향 : 2
//  9시 방향 : 6
deque<int> gears[4];

void right_shift(int num) {
	//뒤에 있는걸 앞으로 가져옴.
	gears[num].push_front(gears[num].back());
	gears[num].pop_back();
}

void left_shift(int num) {
	gears[num].push_back(gears[num].front());
	gears[num].pop_front();
}

int reverse_dir(int dir) {
	return dir * (-1);
} 

int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int t;
			scanf_s("%1d", &t);
			gears[i].push_back(t);
		}
	}
	int K;
	cin >> K;
	for (int n = 0; n < K; n++) {
		int dirs[4] = { 0 }; // 0 이면 가만히
		pair<int, int> rotation;
		cin >> rotation.first >> rotation.second;
		dirs[rotation.first - 1] = rotation.second;
		// 앞
		for (int i = rotation.first - 2; i >= 0; i--) {
			if (gears[i][2] != gears[i + 1][6])
				dirs[i] = reverse_dir(dirs[i + 1]);
		}

		// 뒤
		for (int i = rotation.first; i < 4; i++) {
			if (gears[i-1][2] != gears[i][6])
				dirs[i] = reverse_dir(dirs[i-1]);
		}
		
		// 회전
		for (int i = 0; i < 4; i++) {
			if (dirs[i] == 1)
				right_shift(i);
			else if (dirs[i] == -1)
				left_shift(i);
		}
	}

	int rslt = 0;
	for (int i = 0; i < 4; i++) {
		rslt += ( gears[i][0] ) * (pow(2,i));
	} 
	cout << rslt << endl;
	return 0;

}