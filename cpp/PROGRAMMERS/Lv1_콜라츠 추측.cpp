#include <iostream>
#include <string>
#include <vector>


using namespace std;

int solution(int num) {
	int answer = 0;
	long long ll_num = num;
	while (ll_num!= 1) {
		ll_num = (ll_num & 1 ? (ll_num * 3) + 1 : ll_num / 2 );
		if (++answer >= 500)
			return -1;
	}
	return answer;
}

int main() {
	cout << solution(626331)<< endl;
	return 0;
}