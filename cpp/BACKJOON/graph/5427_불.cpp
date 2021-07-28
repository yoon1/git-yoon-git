#include <iostream>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
int w, h;

int main() {
	int T;
	cin >> T ;
	for (int testCase = 0; testCase < T; testCase++) {
		// 입력
		scanf("%d %d\n", &w, &h);
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%c", &map[i][j]);
			}
			char space; scanf("%c", &space);
		}
		// 상근이의 이동

		// 불의 이동
		/* 
		for (int i = 0; i < N; i++) {

		}
		*/

	}

	return 0;
}