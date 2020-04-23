#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int count_A = 0, count_B = 0 , count_C = 0;
	char A[3] = { 'A','B','C' };
	char B[4] = { 'B','A','B','C' };
	char C[6] = { 'C','C','A','A','B','B' };
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		char t;
		cin >> t;
		if (A[i % 3] == t)
			count_A++;
		if (B[i % 4] == t)
			count_B++;
		if (C[i % 6] == t)
			count_C++;
	}
	int maxCount = max(count_A, count_B);
	maxCount = max(maxCount, count_C);

	cout << maxCount << endl;
	if (maxCount == count_A)
		cout << "Adrian" << endl;
	if (maxCount == count_B)
		cout << "Bruno" << endl;
	if (maxCount == count_C)
		cout << "Goran" << endl;

	return 0;
 }