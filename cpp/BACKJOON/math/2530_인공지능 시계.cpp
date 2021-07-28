#include <iostream>

using namespace std;

const int S = 60;

int main() {
	int h, m, s, t;
	cin >> h >> m >> s;
	cin >> t;
	
	int th, tm, ts;
	tm = t / S;
	ts = t % S;
	th = tm / S;
	tm = tm % S;
	
	
	cout << h + th << m + tm << s + ts;
	return 0;
}