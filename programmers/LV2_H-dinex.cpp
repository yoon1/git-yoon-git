#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 0; i < citations.size(); i++) {
		int p1 = min(i + 1, citations[i]);
		int p2 = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= p1 ) {
				p2 = citations.size() - j;
				break;
			}
		}
		//int p3 = citations[i];
		//cout << "# " << i+1 << "," << citations[i] << "," << p2  << endl;
		answer = max(answer, min(p1, p2));
	}
	return answer;
}

int main() 
{
	cout << solution({ 2,7,5 }) << endl;// ANSWER: 3 
	cout << solution({ 22,42 }) << endl;// ANSWER: 2
	cout << solution({ 0,0,0,0,0 }) << endl;
	cout << solution({ 2,0,6,1,5 }) << endl;
	cout << solution({ 0,1,9}) << endl;
	cout << solution({ 0, 0, 1}) << endl;
	cout << solution({ 1,1,2,1,1 }) << endl;
}