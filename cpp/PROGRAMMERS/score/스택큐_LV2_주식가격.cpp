#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int count = 0;
	for (int i = 0; i < prices.size(); i++) {
		for (int j = i+1; j < prices.size(); j++) {
		//	cout << prices[i] << "," << prices[j] << endl;
			count++;
			if (prices[i] > prices[j]) break;
		}
		answer.push_back(count);
		count = 0;
	}
	for (int a : answer) {
		cout << a << "," ;
	}
	return answer;
}

int main() {
	solution({1, 2, 3, 2, 3});
	return 0;
}