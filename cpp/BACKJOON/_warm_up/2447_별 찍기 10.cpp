#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		bool flag = (i % 2 == 0) ? true : false;
		for (int j = 0; j < N*2; j++){
			cout << (flag ? "*" : " ");
			flag = !flag;
		}
		cout << "\n";
	}
	return 0;
}