#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minCount;

bool visited[100];

string global_begin;
string global_target;
vector<string> global_words;
int getDiffCount(string from, string to) {
	int diffCount = 0;
	for (int i = 0; i < from.length(); i++) {
		if (from[i] != to[i]) {
			diffCount++;
			if (diffCount >= 2)
				return -1;
		}
	}
	return diffCount;
}
void dfs(string word, int cnt) {
	if (word == global_target) {
		minCount = min(cnt, minCount);
		return;
	}
	for (int i = 0; i < global_words.size(); i++) {
		if (visited[i]) continue; // 방문 안한거만 할거임!!
		int diffCount = getDiffCount(word, global_words[i]);
		if (diffCount == 1) {
			visited[i] = true;
			dfs(global_words[i], cnt + diffCount);
			visited[i] = false;
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	minCount = 987654321;
	global_begin = begin;
	global_target = target;
	global_words = words;
	dfs(begin, 0);
	if (minCount == 987654321)
		return 0;
	return minCount;
}