#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	int N = 0;
	int M = 0;
	int MMax, MMin = 0;
	int appleNumber, applePosition = 0;
	int total = 0;
	int position = 0;

	cin >> N >> M;
	cin >> appleNumber;

	MMin = 1;
	MMax = M;

	for (int i = 1; i <= appleNumber; i++) {
		cin >> applePosition;
		if (MMax < applePosition) {
			total += applePosition - MMax;
			MMax = MMax + (applePosition - MMax);
			MMin = MMax - M + 1;
		}
		else if (MMax >= applePosition && MMin <= applePosition) {
		}
		else {
			total += MMin - applePosition;
			MMin = MMin - (MMin - applePosition);
			MMax = MMin + M - 1;
		}
	}
	cout << total;

	return 0;
}