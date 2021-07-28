#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < arr1.size(); i++) {
		string str = "";
		for(int j = 0; j < n; j++){
			bool b = ((arr1[i] & (1 << j) | (arr2[i] & (1 << j))));
			str += b ? "#" : " ";
		}
		reverse(str.begin(), str.end());
		answer.push_back(str);
	}
	return answer;
}