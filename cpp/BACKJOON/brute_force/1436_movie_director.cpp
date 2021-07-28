#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int num = 665;
	int count = 0;

	string  s;

	cin >> n;

	while (num++) {
		s = to_string(num);

		if (s.find("666") != -1) {
			++count;
		}

		if (count == n) {
			cout << num << endl;
			break;
		}
	}
	return 0;
}