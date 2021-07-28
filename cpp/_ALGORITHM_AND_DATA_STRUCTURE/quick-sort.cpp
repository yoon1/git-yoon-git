#include <stdio.h>

int number = 10;
int data[] = { 1,10,5,8,7,6,4,3,2,9 };

void show() {
	int i;
	for (i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}
}

// start : ������ �����ϴ� ù��°
// end : ������ �����ϴ� ������
void quickSort(int* data, int start, int end) {
	if (start >= end) { // ���Ұ� 1���� ��� �״�� �α�
		return;
	}

	int key = start; // Ű�� ù ��° ���� - key : pivot
	int i = start + 1; // Ű ���� ���� ���Ҹ� �Ϲ������� ó�� ���ҷ� ��� ������ +1
	int j = end;
	int temp; // �� ������ �Ͼ �� ����� ���� ����.

	while (i <= j) { // ������������ �ݺ�.
		while (i <= end && data[i] <= data[key]) { // Ű ������ ū ���� ����������
			i++;
		}

		while (j > start && data[j] >= data[key]) { // Ű ������ ���� ���� ����������
			j--;
		}
		if (i > j) { // ���� ������ ���¸� Ű ���� ��ü
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { // �������� �ʾҴٸ� i�� j�� ��ü
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	quickSort(data, start, j - 1); 
	quickSort(data, j + 1, end);
}

int main(void) {
	quickSort(data, 0, number - 1);
	show();
	return 0;
}