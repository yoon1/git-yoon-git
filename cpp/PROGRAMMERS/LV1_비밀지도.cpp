#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < arr1.size(); i++) {
		arr1[i] = arr1[i] | arr2[i];
		string str = "";
		for(int j=0; j < n;j++){
			str += (arr1[i] & (1 << j)) ? "#" : " ";
		}
		answer.push_back(str);
		cout << str << endl;
	}

	return answer;
}

int main() {
	solution(5, { 9,20,28,18,11 }, { 30,1,21,17,28 });
	return 0;
}