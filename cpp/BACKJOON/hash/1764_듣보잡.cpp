#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char name[21];
	int N, M;
	int answer = 0;
	set<string> s;
	set<string> answers;
	scanf("%d %d", &N, &M);
	for(int i=0; i < N; i++){ 
		scanf("%s", &name); 
		s.insert(name);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", &name);
		if (s.find(name) != s.end())
			answers.insert(name);
	}
	cout << answers.size() << "\n";
	for (auto it = answers.begin(); it != answers.end(); it++){
		cout << *it<< "\n";
	}
	return 0;

}