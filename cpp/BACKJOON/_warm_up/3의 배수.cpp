#include <iostream>
#include <string>

using namespace std;

string s;

bool solution(string cur) {
	int t = 0;
	if (cur.length() < 2) return true;
	for (int i = 0; i < cur.length(); i++) 
		t += int(cur[i] - '0');
	s = to_string(t);

	return false;
}

int main() {
	int ret = 0;
	cin >> s;
	while (!solution(s)) ret++;	
	printf("%d\n%s", ret, ((stoi(s) % 3 == 0) ? "YES" : "NO"));

	return 0;
}