#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
bool compare(int a, int b) {
	return a < b; // 오름차순
	//return a < b; // 내림차순
}
int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	
	sort(a, a + 10, compare); 
	// 첫번째 메모리주소, 마지막 메모리 주소를 넣어주면 되요.
	// 이 한문장만으로 소팅이 가능하다니!!!
	// sort함수의 강력한 
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	

}
