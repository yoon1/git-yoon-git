#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

const int CASE = 10;
const int END = 99; //goal
struct Target{
	int pos;
	int dir;
};

vector<int> square[4];
Target target[4] = { 0 }; // 말의 위치
int dice[10] = { 0 };
int maxVal = 0; 
int idx = 1;
void dfs(vector<int> res) { 
	if( res.size() == CASE ) {
		int total = res[0] + res[1] + res[2] + res[3] + res[4] + res[5] + res[6] + res[7] + res[8] + res[9];
		if (maxVal < total) {
			//cout << "# " << idx++ << " : " << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << " " << res[4] << " " << res[5] << " " << res[6] << " " << res[7] << " " << res[8] << " " << res[9] << endl;
			maxVal = total;
		}
		return;
	}
	for (int num = 0; num < 4; num++) { // 4개의 말.
		int n = res.size();
		int cur = target[num].pos;
		int cd = target[num].dir;
		int next = cur + dice[n]; // target의 위치에다가 dice를 더합니다.
		int nd = cd;
		int point = 0;
		if (cur == END)
			continue;

		if (cd == 0){
			if (next == 5 || next == 10 || next == 15) {// curb
				nd = next / 5; // 각각 1,2,3
				next = 0;
			}
		}
		if (next >= square[nd].size()) {
			if ( nd >= 1 && nd <= 3 ) {// dtd
				next = next - square[nd].size();
				nd = 4; 
			}
		}
		if (next < square[nd].size()) {// END아님, 정상적으로 이동할거임
			// 같은 게 있으면? 움직이지 않음.
			if ( (target[0].pos == next && target[0].dir == nd) ||
				 (target[1].pos == next && target[1].dir == nd) ||
				 (target[2].pos == next && target[2].dir == nd) ||
				 (target[3].pos == next && target[3].dir == nd) )
				continue;
			point = square[nd][next];
			if ( point == 40 && (
				(target[0].pos != 99 && square[target[0].dir][target[0].pos] == point) ||
				(target[1].pos != 99 && square[target[1].dir][target[1].pos] == point) ||
				(target[2].pos != 99 && square[target[2].dir][target[2].pos] == point) ||
				(target[3].pos != 99 && square[target[3].dir][target[3].pos] == point)))
				continue;
			
		}
		else{
			next = END;
		}

		// 방향 변경
		target[num].pos = next;
		target[num].dir = nd;
		res.push_back(point); // 점수 
		dfs(res);
		res.pop_back();
		target[num].pos = cur;
		target[num].dir = cd;
	}
}

int main() {
	// INPUT : 주사위 값  
	for (int i = 0; i < CASE; i++) 
		cin >> dice[i];
	
	square[0] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 };
	square[1] = { 10, 13, 16, 19 };
	square[2] = { 20, 22, 24 };
	square[3] = { 30, 28, 27, 26 };
	square[4] = { 25, 30, 35, 40 };
	
	vector<int> res;
	dfs(res);
	
	cout << maxVal; //  얻을 수 있는 최댓값
	return 0;
} 