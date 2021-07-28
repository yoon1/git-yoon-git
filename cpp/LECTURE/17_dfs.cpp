#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7]; // �湮ó��
vector<int> a[8]; // 7���� ��尡 ������ �� �ְ� ������־���.

void dfs(int x) {
	if (c[x]) return; //���� ��带 �湮�ߴٸ� return�ؼ� �Լ��� ���� �� �ְ�.
	c[x] = true; // ó�� �湮�ϴ� �Ÿ� �湮 ó��.
	cout << x << ' '; // ���

	for (int i = 0; i < a[x].size(); i++) { // ����ؼ� �ڱ� ��带 �ݺ������� ����..
		int y = a[x][i];
		dfs(y);
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

	dfs(1); // �������� 1�̶�� ����־����ϴ�.
	return 0;
}