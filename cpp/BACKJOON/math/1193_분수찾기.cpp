#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;
	int child, parent;
	int num = 0;
	int i = 0;
	bool flag = true;
	while(flag){
		num++;
		for (child = 1, parent = num; child <= num; child++, parent--) {
			if (++i >= N) {
				flag = false;
				break;
			}
		}
	}
	if (num%2 == 0) cout << child << "/" << parent;
	else cout << parent << "/" << child;
	return 0;
}