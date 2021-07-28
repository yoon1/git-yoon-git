#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
int main() {
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf_s("%d", &x);
		int gap = max_heap.size() - min_heap.size(); 
		if (max_heap.empty())
			max_heap.push(x);
		else if (max_heap.size() == min_heap.size())
			max_heap.push(x);
		else
			min_heap.push(x);

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int t_max = max_heap.top();
			int t_min = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(t_min);
			min_heap.push(t_max);
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}
