#include <iostream>
#define FIVE 5
#define THREE 3

using namespace std;

int main() {
	int N;
	int total_count = -1;
	cin >> N;
	for (int five_count = N / FIVE; five_count >= 0; five_count--) {
		int remain = N - ( FIVE * five_count);
		if (remain == 0) {
			total_count = five_count;
			break;
		}
		if (remain % 3 == 0) {
			total_count = (remain / THREE) + five_count;
			break;
		}
	}
	cout << total_count << endl;
	return 0;
}
