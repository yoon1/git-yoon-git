#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer = { 0,0 };
	set<string> s;
	int idx = 0;
	int pre = '0';
	for (string word : words) {
		if (s.find(word) != s.end()) break;
		if (idx != 0 && pre != word[0]) break;
		s.insert(word);
		pre = word[word.length() - 1];
		idx++;
	}
	if ( idx != words.size()){
		answer[0] = ((idx % n )+1);
		answer[1] = ((idx) / n) + 1;
	}
	return answer;
}

int main() {
	//vector<int> result = solution(3, { "tank","kick","know","wheel","land","dream","mother","robot","tank" });
	vector<int> result = solution(5, { "hello","observe","effect","take","either","recognize","encourage","ensure","establish","hang","gather","refer","reference","estimate","executive" });
	//vector<int> result = solution(2, { "hello","one","even","never","now","world","draw" });
	cout << result[0] << "," << result[1] << endl;
	return 0;
}