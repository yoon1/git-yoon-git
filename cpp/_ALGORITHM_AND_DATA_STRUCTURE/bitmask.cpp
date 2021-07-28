#include <iostream>

using namespace std;

// ���� num���� i�ڸ��� ���ڰ� 1���� Ȯ�����ִ� �Լ�.
bool getBit(int num, int i) {
	return (num & (1 << i)) != 0;
}

// ���� num���� i�ڸ��� ���ڸ� 1�� ������ִ� �Լ�.
int setBit(int num, int i) {
	return (num | (1 << i));
}

int clearBit(int num, int i) {
	return num & ~(1 << i);
}

// ���� num���� i�ڸ��� ���� �̻��� 0��Ʈ�� �����, �� �����δ� �״�� �δ� ��
int clearLeftBits(int num, int i) {
	return num & ((1 << i) - 1);
}

// ���� num���� i�ڸ��� ���� ���δ� �״�� �ΰ�, ���ϴ� 0��Ʈ�� ���� ��
int clearRightsBits(int num, int i) {
	return num & (-1 << (i + 1));
}

// ���� num���� i�ڸ��� ���ڸ� val������ setting���ִ� ��
int updateBit(int num, int i, bool val) {
	return (num & ~(1 << i)) | ((val ? 1 : 0) << i);
}
int main() { 
	// 10101001
	cout << updateBit(169, 3, false);
	// �ش� ��Ʈ�� 0���� �����غ��Կ�.
	// 10100001
	return 0;
}
