#include <iostream>
#define MAX 100

using namespace std;

int N, L, result;
int map[MAX][MAX];

void go(int i, bool flag) { // row 번호 혹은 col 번호
	int cnt = 1;	
	for (int j = 0; j < N - 1; j++) {
		int d = flag ? (map[i][j + 1] - map[i][j]) : (map[j+1][i] - map[j][i]); // 다음 
		if (d == 0) // 차이가 0이면 count++
			cnt++;
		else if (d == 1 && cnt >= L) // 더 높아진다면, 그리고 count의 갯수가 L이라면 
			cnt = 1;
		else if (d == -1 && cnt >= 0 ) // 더 낮아진다면
			cnt = -L + 1;
		else return; // 2칸 이상 차이남
	}
	if (cnt >= 0) result += 1; // ok
}
int main() {
	cin >> N >> L;
	for(int i=0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++) {
		go(i, true); 
		go(i, false);
	}


	cout << result;
	return 0;
}