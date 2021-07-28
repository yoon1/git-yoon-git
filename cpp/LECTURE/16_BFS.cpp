#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; // �湮 ó���� ���� ���� �迭. checked�� �����Դϴ�. �湮�ߴٴ� �� ǥ����!
vector<int> a[8]; // �� ����� �ε����� 1���� ó���� �� �ֵ��� 8�� ��������~

void bfs(int start) { 
	queue<int> q; 
	q.push(start); // �� ÷���� queue�� �������� �־��ݴϴ�.
	c[start] = true; 
	while (!q.empty()) { // queue�� �􋚱��� �ݺ�.
		int x = q.front(); // queue���� �ϳ� ������ ���� x�� ����.
		q.pop(); // x���
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) { // i�� ������ ���� �ϳ��� �湮�� �ϸ鼭 
			int y = a[x][i];
			if (!c[y]) { // �湮�� �� ����? ��� �����ϰ�.
				q.push(y); // �ƴϸ� �̷��� queue�� ����ָ� �˴ϴ�.
				c[y] = true; // �湮ó��.
			}
		}
	}

}
int main() {
	a[1].push_back(2); // 1-2
	a[2].push_back(1); // ������̱� ������ ���μ��� ����.. (�������� 2���� ��ɾ ���� �Ǵ°�)
 
	a[1].push_back(3); // 1-3
	a[3].push_back(1);

	a[2].push_back(3); // 2-3
	a[3].push_back(2);

	a[2].push_back(4); // 2-4
	a[4].push_back(2);

	a[2].push_back(5); // 2-5
	a[5].push_back(2);

	a[4].push_back(5); // 4-5
	a[5].push_back(4);

	a[3].push_back(6); // 3-6
	a[6].push_back(3);

	a[3].push_back(7); // 3-7
	a[7].push_back(3);

	a[6].push_back(7); // 6-7
	a[7].push_back(6);

	bfs(1); // �������� 1�̶�� ����־����ϴ�.
	
	return 0;
}