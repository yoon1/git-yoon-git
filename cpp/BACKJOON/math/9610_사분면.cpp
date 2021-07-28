#include <iostream>
using namespace std;

int N;
int sbm[5] = {0};
int main() {
	cin >> N; 
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (x == 0 || y == 0) sbm[0]++; // รเ
		if (x > 0 && y > 0) sbm[1]++; // 
		else if (x < 0 & y > 0) sbm[2]++;
		else if (x < 0 & y < 0) sbm[3]++;
		else if (x > 0 & y < 0) sbm[4]++;
	}
	
	for (int i = 1; i <= 4; i++) 
		cout << "Q" << i << ": " << sbm[i] << endl;
	cout << "AXIS: " << sbm[0] << endl;
	
	return 0;
}
