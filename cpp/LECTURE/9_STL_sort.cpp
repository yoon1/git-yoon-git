#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
bool compare(int a, int b) {
	return a < b; // ��������
	//return a < b; // ��������
}
int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	
	sort(a, a + 10, compare); 
	// ù��° �޸��ּ�, ������ �޸� �ּҸ� �־��ָ� �ǿ�.
	// �� �ѹ��常���� ������ �����ϴٴ�!!!
	// sort�Լ��� ������ 
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	

}
