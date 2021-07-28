#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
struct LINE {
	int x1, y1, x2, y2;
};
LINE L[3001];
int r[3001]; // index의 root 저장.
int cnt[3001]; // intdex를 root로 하는 그룹 구성원 수.

int getParent(int a) {
	if (r[a] == a) return a;
	else return r[a] = getParent(r[a]); // 갱신하며 찾기.
}

void join(int a, int b) {
	r[getParent(a)] = getParent(b);
}

ll ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	ll ret = (x1*y2 + x2 * y3 + x3 * y1) - (y1*x2 + y2 * x3 + y3 * x1);
	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	// 만나면 true, 아니면 false -> 선분 CCW 곱의 결과가 음수여야지만 안 만나는 경우.
	// 예외 처리가 필요. 0인 경우도 예외 처리에 포함시켜야 한다(평행이동 하면 관통하지 않고 만나기만 하는 경우)
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||
			(x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) return false;
		else if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||
			(y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) return false;
		else
			return true;
	}
	return false; // 애초에 양수면 교차하지 않음.
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) // 유니온 파인드 할 때 편하ㅑ라고 1-indexed
		cin >> L[i].x1 >> L[i].y1 >> L[i].x2 >> L[i].y2;
	for (int i = 1; i <= n; i++) r[i] = i; // root자기 자신으로 초기화.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (isCross(L[i].x1, L[i].y1, L[i].x2, L[i].y2, L[j].x1, L[j].y1, L[j].x2, L[j].y2))
				join(i, j);
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[getParent(i)]++;
	}

	int groupCnt = 0, maxCnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > 0) groupCnt++;
		if (cnt[i] > maxCnt) maxCnt = cnt[i];
	}
	cout << groupCnt << "\n" << maxCnt;
	return 0;
}