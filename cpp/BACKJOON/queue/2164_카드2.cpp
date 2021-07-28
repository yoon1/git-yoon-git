#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int qPop() {
	int temp = q.front();
	q.pop();
	return temp;
}
 
int main() {
	int N;

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	while (q.size() > 1) {
		q.pop();
		if (!(q.size() > 1)) break;
		int temp = qPop();
		q.push(temp);
	}

	int result = qPop();
	cout << result << endl;

	return 0;
}