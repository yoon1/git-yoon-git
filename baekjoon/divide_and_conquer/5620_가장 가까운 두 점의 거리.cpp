#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
	int x, y;
};

bool cmp_x(Point a, Point b) { // x순 정렬(오름)
	return a.x < b.x;
}
bool cmp_y(Point a, Point b) { // y순 정렬(오름)
	return a.y < b.y;
}

int distance(Point &p, Point &q) { // 두 점 사이 거리 제곱
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
}

int solve(vector<Point>::iterator it, int n) {
	if (n == 2) // 두 점? 거리 반환
		return distance(it[0], it[1]);
203.	if (n == 3) // 세 점? 최소 거리 반환
		return min({ distance(it[0], it[1]), distance(it[1], it[2]), distance(it[2], it[0]) }); // 3점 중 가장 작은것
	int line = (it[n / 2 - 1].x + it[n / 2].x) / 2; // 기준 line - 가운데
	int d = min(solve(it, n / 2), solve(it + n / 2, n - n / 2)); // 왼쪽, 오른쪽.(분할) ==> 점 갯수로 분할한거임
	vector<Point> mid; 
	mid.reserve(n);
	for (int i = 0; i < n; i++) {
		int t = line - it[i].x;
		if(t*t < d) // 거리가 더 짧으면 mid에 담고
			mid.push_back(it[i]);
	}

	sort(mid.begin(), mid.end(), cmp_y); // y좌표별로 정렬

	int mid_size = mid.size(); 

	// y좌표 범위(y간 거리가 d를 넘어가는 점은 계산할 필요도 없음)
	for (int i = 0; i < mid_size - 1; i++) 
		for(int j = i+1; j < mid_size && (mid[j].y - mid[i].y)* (mid[j].y - mid[i].y) < d; j++)
			d = min(d, distance(mid[i], mid[j]));
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<Point> p;
	for (int i = 0; i < N; i++) {
		Point t;
		cin >> t.x >> t.y; 
		p.push_back(t);
	}

	// x 오름차순 정렬
	sort(p.begin(), p.end(), cmp_x); 
	
	cout << solve(p.begin(), N); 
	return 0;
}