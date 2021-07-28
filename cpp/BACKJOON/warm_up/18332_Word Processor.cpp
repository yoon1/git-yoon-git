#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, K;
	vector<string> v;
	cin >> N >> K;
	for(int i=0; i < N; i++) {
		string t;
		cin >> t;
		v.push_back(t);
	}

	
	//for (int i = 0; i < v.size(); i++) {
	int i = 0;
	while (i < v.size()) {
		string t = "";
		while ( (t + v[i]).length() <= K ) {
			t += v[i];
			i++;
			if (i == v.size())
				break;
		}
		cout << t << endl;
	}
	
	return 0;
}