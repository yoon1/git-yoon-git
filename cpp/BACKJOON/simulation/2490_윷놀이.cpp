#include <iostream>
#include <map>
#include <string>

using namespace std;



map<int, string> m;

void dict_init() {
	// ���� ���� = ���� ����
	m[0] = 'D'; // ��
	m[1] = 'C'; // ��
	m[2] = 'B'; // ��
	m[3] = 'A'; // ��
	m[4] = 'E'; // ��
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