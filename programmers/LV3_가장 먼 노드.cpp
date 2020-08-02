#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	vector<bool> visited(n+1);
	vector<int> v[20001];
	queue<pair<int, int>> q;
	for (int i = 0; i < edge.size(); i++) {
		v[edge[i][0]].push_back(edge[i][1]);
		v[edge[i][1]].push_back(edge[i][0]); 
	}
	q.push({ 1, 0 });
	visited[1] = true;
	pair<int, int> maxCount = { 0,0 }; // max ¼ö, °¹¼ö
	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		if (maxCount.first < d) 
			maxCount = { d, 1 };
		else if (maxCount.first == d)
			maxCount.second++;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) 
			if (!visited[v[x][i]] && (visited[v[x][i]] = !visited[v[x][i]])) 
				q.push({ v[x][i], d + 1 });
	}
	return maxCount.second;
}
