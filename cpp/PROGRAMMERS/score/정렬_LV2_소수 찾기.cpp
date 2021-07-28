#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;
bool visited[10];
int answer = 0;
bool isDecimal(int n) {
	if (n <= 1) return false;
	for (int i = 2; i < n; i++) 
		if (n % i == 0) 
			return false;
	return true;
}

void dfs(string numbers, int n, string t) {
	if (t.length() > numbers.size()) 
		return; 
	int num = 1;
	stringstream(t) >> num;
	if (find(s.begin(), s.end(), num) == s.end()) {
		if ( isDecimal(num) ) answer++;
		s.insert(num);
	}
	for (int i = 0; i < numbers.length(); i++) {
		if (visited[i])continue;
		visited[i] = true;
		string cur = t;
		t += numbers[i];
		dfs(numbers, i+1, t);
		t = cur;
		visited[i] = false;
	}
	return;
}
int solution(string numbers) {
	string t = "";
	dfs(numbers, 0, t);
	return answer;
}
int main() {
	cout << solution("011") << endl;
	return 0;
}