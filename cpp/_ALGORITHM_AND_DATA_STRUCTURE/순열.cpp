#include <iostream>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char *list, int i, int n)
// list[i]���� list[n]������ ���ҷ� ������ ��� ���� ���
// {a, b, c, d}�� ��� �ʱ� ȣ�� = perm(list, 0, 3)
{
	int j, temp;
	if (i == n) { // �� �ϳ��� ������ ����. �׳� ������ڡ�
		for (j = 0; j <= n; j++)
			printf("%c", list[j]);
		printf("\n");
	}
	else { // �ϳ� �̻��� ���� ����. ��������� ���
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}

int main() {
	char list[] = { 'a','b','c','d' };
	perm(list, 0, 3);
	return 0;
}