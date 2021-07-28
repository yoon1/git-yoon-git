#include <iostream>

using namespace std;

int main () {
	int N;
	int P;
	long long Y;
	int Y_rank = 1, Y_same_rank = 1;

	long long score;

	cin >> N >> Y >> P;
	
	for (int i = 0; i < N; i++) {
		cin >> score;
		if (score> Y) Y_rank++;
		if (score >= Y) Y_same_rank++;
	}
	
	if (Y_same_rank > P) cout << "-1";
	else cout << Y_rank;
	
}

