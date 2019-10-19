#include <iostream>

using namespace std;

int main() {
	int test_case = 0;
	
	cin >> test_case;
	for (int T = 1; T <= test_case; T++)
	{
		int boxWeight[100] = { 0 };
		int check[100] = { 0 };
		int needs[100] = { 0 };
		int remain = 0;
		int leftFlag = 0;
		int rightFlag = 0;
		int count = 0; // count
		int N = 0; // 박스 수
		int tmp = 0; 

		cin >> N;
		
		for (int j = 0; j < N; j++){
			cin >> boxWeight[j];
		}
		
		for (int m = 0; m < N; m++) {
			for (int n = 0; n < N; n++) {
				if (boxWeight[m] < boxWeight[n]) {
					tmp = boxWeight[m];
					boxWeight[m] = boxWeight[n];
					boxWeight[n] = tmp;
				}
			}
		}

		for (int j = 0; j < N; j++) {
			if (50 % boxWeight[j] == 0) remain = 0;
			else { remain = 1; }
			check[j] = 1;
			needs[j] = (50 / boxWeight[j]) + remain;
			//cout << "BOX WEIGHT : " << boxWeight[j] << endl;
			//cout << "CHECK : " << check[j] << endl;
			//cout << "NEDDS : " << needs[j] << endl;
		}
		
		for (rightFlag = N-1; rightFlag >= 0; rightFlag--) {
			//cout << "( leftFlag, rightFlag ) : " << leftFlag << "," << rightFlag << endl;
			//cout << "** check[rightFlag]" << check[rightFlag] << endl;
			//cout << "** needs[rightFlag]" << needs[rightFlag] << endl;
			if (check[rightFlag] != 0 && rightFlag - leftFlag >= needs[rightFlag]-1 ) {
				for (int k = 1; k < needs[rightFlag]; k++) {
					check[leftFlag++] = 0;
				}
				check[rightFlag] = 0;
				count++;
				//cout << "지금까지 : " << T << " " << count << "\n";
			}
			else {
				//cout << "종료 : " << rightFlag << endl;
				break;
			}
		}
		cout << "#" << T << " " << count << "\n";
	}

	return 0;
}

