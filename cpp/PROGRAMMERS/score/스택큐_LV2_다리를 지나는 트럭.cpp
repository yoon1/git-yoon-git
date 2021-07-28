#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int cur_weight = 0;
	deque<pair<int, int>> truck_on_bridge;
	int i = 0;
	while (!truck_on_bridge.empty() || i < truck_weights.size()) {

		if (i < truck_weights.size()) {
			if (cur_weight + truck_weights[i] <= weight) {
				truck_on_bridge.push_back(make_pair(truck_weights[i], 0));
				cur_weight += truck_weights[i];
				i++;
			}
		}
		
		answer++;
		int pop_count = 0;

		for (int j = 0; j < truck_on_bridge.size(); j++) {
			truck_on_bridge[j].second++;
			if (truck_on_bridge[j].second == bridge_length) {
				cur_weight = cur_weight - truck_on_bridge[j].first;
				pop_count++;
			}
		}
		while(pop_count-- > 0) {
			truck_on_bridge.pop_front();
		}
	}
	cout << answer+1 << endl;
	return answer;
}

int main() {
	solution(2, 10, { 7, 4, 5, 6 });
	solution(100, 100, { 10 });
	solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10});

	return 0;
}