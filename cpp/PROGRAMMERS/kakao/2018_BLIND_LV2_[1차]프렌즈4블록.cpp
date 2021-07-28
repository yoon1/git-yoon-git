#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

pair<int, int> dir[4] = { {0,0},{0,1},{1,0},{1,1} };
deque<char> dq[30]; // col별
bool isPop(int y, int x, char chter) {
	for (int i = 0; i < 4; i++) 
		if (dq[y + dir[i].first][x + dir[i].second] != chter) 
			return false;
	return true;
}
int solution(int m, int n, vector<string> board) {
	for (int col = 0; col < n; col++) 
		for (int row = 0; row < m; row++) 
			dq[col].push_back(board[row][col]); // dq에 넣음.
	int pop_count = 0;
	int cur_count = 0;
	do {
		cur_count = 0;
		set<pair<int, int>> s;
		for (int col = 0; col < m-1; col++) {
			for (int row = 0; row < n-1; row++) {
				if (dq[row][col] != '.' && isPop(row,col,dq[row][col])) {
					for (int i = 0; i < 4; i++) {
						s.insert({ row + dir[i].first, col + dir[i].second});
					}
				}
			}
		}
		// pop
		cur_count = s.size();
		for (auto it = s.begin();it != s.end();it++){
			dq[it->first].erase(dq[it->first].begin() + it->second);
			dq[it->first].push_front('.');
		}  
		pop_count += cur_count;
	} while (cur_count != 0);
	return pop_count;
}

int main() {
	//cout << solution(4,5,{"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;
	cout << solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << endl;
	
	return 0;
}