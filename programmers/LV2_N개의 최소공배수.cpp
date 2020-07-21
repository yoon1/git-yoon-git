#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 101

using namespace std;

int solution(vector<int> arr) {
	int answer = 1;
	sort(arr.begin(), arr.end());
	int maxValue = arr[arr.size() - 1]; 
	vector<int> v;
	for (int i = 2; i <= maxValue; i++) {
		int count = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] % i == 0) {
				arr[j] = arr[j] / i;
				count++;
			}
		}
		if (count > 0) 
			v.push_back(i--);
	}

	for (int i = 0; i < v.size(); i++)
		answer *= v[i];

	return answer;
}