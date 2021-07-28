#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> bill;
	int total, total_bill = 0;
	cin >> total;
	
	for (int i = 0; i < 10; i++) {
		int t;
		cin >> t;
		total_bill += t;
		bill.push_back(t);
	}
	for (int i = 0; i < bill.size(); i++) {
		if (total_bill - bill[i] == total) {
			cout << bill[i];
			return;
		}
	}
	return 0;
}