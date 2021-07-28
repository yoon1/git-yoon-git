#include <iostream>

using namespace std;

// 숫자 num에서 i자리의 숫자가 1인지 확인해주는 함수.
bool getBit(int num, int i) {
	return (num & (1 << i)) != 0;
}

// 숫자 num에서 i자리의 숫자를 1로 만들어주는 함수.
int setBit(int num, int i) {
	return (num | (1 << i));
}

int clearBit(int num, int i) {
	return num & ~(1 << i);
}

// 숫자 num에서 i자리의 숫자 이상은 0비트로 만들고, 그 밑으로는 그대로 두는 것
int clearLeftBits(int num, int i) {
	return num & ((1 << i) - 1);
}

// 숫자 num에서 i자리의 숫자 위로는 그대로 두고, 이하는 0비트로 만들 것
int clearRightsBits(int num, int i) {
	return num & (-1 << (i + 1));
}

// 숫자 num에서 i자리의 숫자를 val값으로 setting해주는 것
int updateBit(int num, int i, bool val) {
	return (num & ~(1 << i)) | ((val ? 1 : 0) << i);
}
int main() { 
	// 10101001
	cout << updateBit(169, 3, false);
	// 해당 비트를 0으로 셋팅해볼게요.
	// 10100001
	return 0;
}
