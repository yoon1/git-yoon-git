#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int A, B, C;
	int min_time = 99999999;
	int max_time = 0;
	pair<int, int> car[3];
	int cost_board[4] = { 0 };
	cin >> cost_board[1] >> cost_board[2] >> cost_board[3] ;
	for (int i = 0; i < 3; i++) {
		cin >> car[i].first >> car[i].second;
		min_time = min(car[i].first, min_time);
		max_time = max(car[i].second, max_time);
	}

	int cost = 0;
	for (int time = min_time; time  <= max_time; time++) {
		int quantity = 0;
		for (int i = 0; i < 3; i++) {
			if (car[i].first+1 <= time && car[i].second >= time)
				quantity++;
		}
		cost += ( cost_board[quantity] * quantity );
	}
	cout << cost << endl;
	return 0;
}