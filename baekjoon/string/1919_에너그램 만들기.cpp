#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string strA;
	string strB;
	int a[26] = { 0 };
	int b[26] = { 0 };
	int total = 0;
	
	cin >> strA >> strB;
	for(int i=0; i < strA.length(); i++) {
		a[strA[i] - 'a']++;
	}
	for (int i = 0; i < strB.length(); i++) {
		b[strB[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		total += abs(a[i] - b[i]);
	}

	cout << total << "\n";
	return 0;
 }