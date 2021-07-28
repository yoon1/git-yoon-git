#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> stk;
	
	for (int i = 0; i < moves.size(); i++) {
		int pos = moves[i] -1; // moves[i]-1Àº.. moves[i] = 1 - 1 = 0
		for (int j = 0; j < board[pos].size(); j++) {
			int& ref = board[j][pos];
			if (ref != 0) {
				if (!stk.empty() && stk.back() == ref) {
					stk.pop_back();
					answer+= 2;
				}
				else 
					stk.push_back(ref);	
				ref = 0;
				break;
			}
		}
	}
	return answer;
}
int main() {

	cout << solution({ {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} }, { 1,5,3,5,1,2,1,4 }) << endl;
	return 0;
}