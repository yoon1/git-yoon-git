#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
	int x, y;
};

bool cmp_x(Point a, Point b) { // x�� ����(����)
	return a.x < b.x;
}
bool cmp_y(Point a, Point b) { // y�� ����(����)
	return a.y < b.y;
}

int distance(Point &p, Point &q) { // �� �� ���� �Ÿ� ����
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
}

int solve(vector<Point>::iterator it, int n) {
	if (n == 2) // �� ��? �Ÿ� ��ȯ
		return distance(it[0], it[1]);
203.	if (n == 3) // �� ��? �ּ� �Ÿ� ��ȯ
		return min({ distance(it[0], it[1]), distance(it[1], it[2]), distance(it[2], it[0]) }); // 3�� �� ���� ������
	int line = (it[n / 2 - 1].x + it[n / 2].x) / 2; // ���� line - ���
	int d = min(solve(it, n / 2), solve(it + n / 2, n - n / 2)); // ����, ������.(����) ==> �� ������ �����Ѱ���
	vector<Point> mid; 
	mid.reserve(n);
	for (int i = 0; i < n; i++) {
		int t = line - it[i].x;
		if(t*t < d) // �Ÿ��� �� ª���� mid�� ���
			mid.push_back(it[i]);
	}

	sort(mid.begin(), mid.end(), cmp_y); // y��ǥ���� ����

	int mid_size = mid.size(); 

	// y��ǥ ����(y�� �Ÿ��� d�� �Ѿ�� ���� ����� �ʿ䵵 ����)
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

	// x �������� ����
	sort(p.begin(), p.end(), cmp_x); 
	
	cout << solve(p.begin(), N); 
	return 0;
}