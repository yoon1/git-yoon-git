#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}
	cout << answer;  
	return answer;
}

int main() {
	solution({1, 4, 2}, { 5, 4, 4});
	solution({ 1, 2 }, {3, 4});
	return 0;
}