#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	
/* 	cout << commands.size();
	for (int i = 0; i < commands.size(); i++) {
		cout << commands[i][0] << endl;
		cout << commands[i][1] << endl;
		cout << commands[i][2] << endl;
	}
	*/
	for (int i = 0; i < commands.size(); i++) {
		vector<int> temp = {};
		for (int j = commands[i][0]; j <= commands[i][1]; j++) {
			cout << "[ " << i << "] : " <<array[j - 1] << endl;
			temp.push_back(array[j-1]);	
		}
		cout << "COMM  : " << commands[i][2] - 1 << endl;
		cout << temp[commands[i][2] - 1 ]<< endl;
		cout << "_------------_" << endl;
		std::sort(temp.begin(), temp.end());
		for (int n : temp) {
			cout << n << endl;
		}
		
		cout << "_------------_" << endl;
		answer.push_back(temp[commands[i][2] - 1]);
	}	

	
	 for (int n : answer) {
		cout << n << endl;
	}
	
	
	return answer;
}

int main() {
	solution({ 1, 5, 2, 6, 3, 7, 4 }, {   {2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
	return 0;
}
