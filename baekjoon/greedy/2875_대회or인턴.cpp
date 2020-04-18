#include <iostream>

using namespace std;

int matchTeam(int boy, int girl) {
	if (boy/2 < girl) {
		return boy / 2;
	}
	else return girl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int N, M, K;
	int result = 0;
	int temp = 0;
	cin >> N >> M >> K;
	
	for (int i = 0; i <= K; i++) {
		temp = matchTeam(N - i, M - (K - i));
		if (temp > result) result = temp;
	}

	cout << result;
	return 0;
}

