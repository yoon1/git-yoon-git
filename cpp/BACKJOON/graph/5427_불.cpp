#include <iostream>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
int w, h;

int main() {
	int T;
	cin >> T ;
	for (int testCase = 0; testCase < T; testCase++) {
		// �Է�
		scanf("%d %d\n", &w, &h);
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%c", &map[i][j]);
			}
			char space; scanf("%c", &space);
		}
		// ������� �̵�

		// ���� �̵�
		/* 
		for (int i = 0; i < N; i++) {

		}
		*/

	}

	return 0;
}