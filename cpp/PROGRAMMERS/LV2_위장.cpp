#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;
	for (int i = 0; i < clothes.size(); i++) {
		m[clothes[i][1]]++;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		answer = answer * (it->second + 1);
	}
	answer = answer - 1;
	cout << answer;
	return answer;
}

int main() {
	//solution({{"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear"}, { "green_turban", "headgear"}});
	solution({ {"crow_mask", "face"},{"blue_sunglasses", "face"}, {"smoky_makeup", "face"} });
	return 0;
}