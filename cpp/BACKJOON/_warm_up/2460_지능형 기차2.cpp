#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max_people = 0;
int train_people = 0;

int main() {

	for (int i = 0; i < 10; i++) {
		int down, up; cin >> down >> up;
		train_people -= down;
		train_people += up;
		max_people = max(max_people, train_people);
	}
	cout << max_people;

	return 0;
}