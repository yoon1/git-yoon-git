#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	for (int i = 0; i < arr.size(); i++) {
		if (answer.empty() || answer.back() != arr[i])
			answer.push_back(arr[i]);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";

	}
	return answer;
}

int main() {

	solution({ 1, 1, 3, 3, 0, 1, 1 });
	
	return 0;
}