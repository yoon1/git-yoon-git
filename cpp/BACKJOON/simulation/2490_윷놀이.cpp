#include <iostream>
#include <map>
#include <string>

using namespace std;



map<int, string> m;

void dict_init() {
	// µîÀÇ °¹¼ö = À·ÀÇ »óÅÂ
	m[0] = 'D'; // À·
	m[1] = 'C'; // °É
	m[2] = 'B'; // °³
	m[3] = 'A'; // µµ
	m[4] = 'E'; // ¸ð
}

int main() {
	dict_init();
	
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int t;  cin >> t;
			if(t) cnt++;
		}
		cout << m[cnt] << endl;
	}
	return 0;
}