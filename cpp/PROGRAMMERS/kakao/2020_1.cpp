#include <iostream>
#include <string>
#include <vector>


using namespace std;

/* 
0 0 0 0 0
0 0 1 0 3
0 2 5 0 1
4 2 4 4 2
3 5 1 3 1

=> 1 5 3 5 1 2 1 4
=> 4 (3 (1 1) 3) 2 X 4
*/
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> t;
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j].empty())
				continue;
			int p = board[j][moves[i] - 1];
			if (p != 0) {
				if (!t.empty() && p == t.back()) {
					t.pop_back();
					answer= answer + 2;
				}
				else {
					t.push_back(p);
				}
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}
	return answer;
}

int main() {

	cout << solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, 
		{1, 5, 3, 5, 1, 2, 1, 4});
	return 0;

}