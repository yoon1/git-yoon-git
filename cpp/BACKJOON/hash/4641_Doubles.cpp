#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s;
	int n;
	while ( scanf_s("%d", &n)) {
		if (n == -1) return 0;
		if (n == 0) {
			int count = 0;
			for (auto it = s.begin(); it != s.end(); it++) {
				if (s.find((*it) * 2) != s.end()) {
					count++;
				}
			}
			cout << count << endl;
			s.clear();
		}
		else s.insert(n);
	}
	
	
	return 0;
}