#include <iostream>

using namespace std;
#define MAX 6

int main() {

	std::ios_base::sync_with_stdio(false);
	int coin[MAX] = { 500, 100, 50, 10, 5, 1 };
	int transMoney;

	int count = 0;
	cin >> transMoney;
	
	transMoney = 1000  - transMoney;

	for (int i = 0; i < MAX ; i++) {
		count += transMoney / coin[i];
		transMoney = transMoney % coin[i];
	}

	cout << count;
	return 0;
}

/* 
INPUT : 1000 - 380 = 620
500 1
100 1
10 2
= 4
*/