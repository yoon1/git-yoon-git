#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= n; i++ ) {
		int sum = 0;
		for (int j = i; j <= n; j++) {
			sum += j;
			if (sum == n) answer++;
			if (sum > n) break;
		}
	}
	cout << answer;
	return answer;
}


int main() 
{
	solution(15);
	return 0;
}