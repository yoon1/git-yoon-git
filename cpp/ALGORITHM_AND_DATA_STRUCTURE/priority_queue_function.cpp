#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> mypd;

	int sum(0);

	for (int i = 1; i < 10; i++) mypd.push(i);

	mypd.push(10);
	mypd.push(20);
	mypd.push(50);
	mypd.push(20);
	mypd.push(15);

	for (int it = mypd.size() ; it < mypd.size(); it++) {
		cout << mypd.top() << endl;
		mypd.pop();
	}

	return 0;
}