#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
int tree[4 * NUMBER]; 
// 4�� ���ϸ� ��� ������ Ŀ���� �� �ִ�. 
// ������ ���ؼ� 2�� ���� ���¸� ���� �����̴�.

// 1 : ���׸�Ʈ Ʈ�� ���·� �����
// start : ���� �ε���, end : �� �ε���
int init(int start, int end, int node) { 
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	// ��������� �� �κ����� ���� �ڿ� �� ���� �ڱ� �ڽ����� �Ѵ�.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1); 
	// left + right
}

// 2 : ���� ���� ���ϴ� �Լ�
// start : ���� �ε���, end : �� �ε���
// left, right : ���� ���� ���ϰ��� �ϴ� ����
int sum(int start, int end, int node, int left, int right) { 
	// ���� ��
	if (left > end || right < start) return 0;
	// ���� ��
	if (left <= start && end <= right) return tree[node];
	// �׷��� ���� ���? �� �κ����� ����� ���� ����.
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// 3 : Ư�� ������ ���� �����ϴ� �Լ�
// start : ���� �ε���, end : �� �ε���
// index : ���� ���� �����ϰ��� �ϴ� ���.
// dif : ������ ��.
void update(int start, int end, int node, int index, int dif) { 
	// ���� �ۿ� �ִ� ���
	if (index < start || index > end) return;
	// ���� �ȿ� ������ �������� �ٸ� ���ҵ� ����
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif); // left
	update(mid + 1, end, node * 2 + 1, index, dif); // right
}
int main() {
	// ���� �� Ʈ���� �ε����� �����ϰ�� ��� �ε��� 0���� �����Ѵ�.
	// 1. ���� �� Ʈ�� ����.
	init(0, NUMBER - 1, 1);

	// 2. ���� �� ���ϱ�
	cout << "0���� 11������ ���� �� : " << sum(0, NUMBER - 1, 1, 0, 11) << '\n';
	cout << "3���� 8������ ���� �� : " << sum(0, NUMBER-1, 1, 3, 8) << '\n';

	// 3. ���� �� �����ϱ�
	cout << "�ε��� 5�� ���Ҹ� -5��ŭ ����" << "\n";
	update(0, NUMBER - 1, 1, 5, -5);

	// 2-2. ���� �� ���ϱ�
	cout << "3���� 8������ ���� �� : " << sum(0, NUMBER-1, 1, 3, 8) << '\n';
	return 0;

}