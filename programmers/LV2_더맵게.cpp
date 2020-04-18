#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	while (pq.size() > 1) {
		if (pq.top() >= K) return answer;
		int s1 = pq.top();
		pq.pop();
		int s2 = pq.top();
		pq.pop();
		pq.push(s1 + (s2 * 2));
		answer++;
	}
	if (!pq.empty() && pq.top() >= K) return answer;
	else return -1;
}

int main()
{
	cout << solution({ 0 }, 7) << endl;
	cout << solution({ 1 }, 7) << endl;
	cout << solution({ 1,2 }, 7) << endl;
	cout << solution({ 1,2,10 }, 7) << endl;
	cout << solution({ 1,2,3,9,10,12 }, 7) << endl;
	return 0;
}
