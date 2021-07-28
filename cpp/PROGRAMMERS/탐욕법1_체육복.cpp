#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost.pop_back();
				reserve.pop_back();
			}
		}
	}
	if (reserve.size() == 1 && lost.size() == 1) {
		answer = n - 1;
	} else if (reserve.size() >= lost.size()){
		answer = n;
	}
	else {
		cout << n << lost.size() << reserve.size() << endl;
		answer = n - lost.size() + reserve.size();
	}
	return answer;
}

int main() {

	//cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;
	cout << solution(5, { 2,4 }, { 3 }) << endl;
	return 0;
}


