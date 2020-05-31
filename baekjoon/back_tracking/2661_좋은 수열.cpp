#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//2±îÁö


int N;
//char str[80] = "";
string str;
bool isPromissing(int n, string temp) {
//	cout << " TEMP : " << temp << endl;
	reverse(temp.begin(), temp.end());
	for(int i=1; i <= (n+1)/2; i++){
	//	cout << "~~~~~~" << n<< "," << (n + 1) / 2 << "," << i << endl;
//		cout << "#" << temp.substr(0, i) << "," << temp.substr(i, i) << endl;
		if (temp.substr(0, i).compare(temp.substr(i, i)) == 0) {
			//cout << "FALSE" << endl;
			return false;
		}
	}
	// 0   -- 1   ==> 0,1 -- 1,1
	// 0~1 -- 2~3 ==> 0,2 -- 2,2
	// 0~2 -- 3~5 ==> 0,3 -- 3,3
//	cout << "TRUE\n\n\n" << endl;
	return true;
}

bool flag = false;
void dfs(int n) {
	if ( n == N ) {
		cout << str << endl;
		flag = true;
		return;
	}
	for (int i = 1; i <= 3 && !flag; i++) {
		if (isPromissing(n, str + to_string(i))) {
			string cur = str;
			str += to_string(i);
			dfs(n+1);
			str = cur;
		}
	}
}

int main() {
	cin >> N;
	dfs(0);
	return 0;
}