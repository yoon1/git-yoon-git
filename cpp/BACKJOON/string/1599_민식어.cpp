#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
map<string, string> minsik_dict;
vector<string> origin_word; 
priority_queue<pair<string, int>, vector<pair<string,int>>, greater<pair<string, int>>> pq;

int N;

void dict_init() {
	minsik_dict["a"] = 'a';
	minsik_dict["b"] = 'b';
	minsik_dict["k"] = 'c';
	minsik_dict["d"] = 'd';
	minsik_dict["e"] = 'e';
	minsik_dict["g"] = 'f';
	minsik_dict["h"] = 'g';
	minsik_dict["i"] = 'h';
	minsik_dict["l"] = 'i';
	minsik_dict["m"] = 'j';
	minsik_dict["n"] = 'k';
	minsik_dict["ng"] = 'l';
	minsik_dict["o"] = 'm';
	minsik_dict["p"] = 'n';
	minsik_dict["r"] = 'o';
	minsik_dict["s"] = 'p';
	minsik_dict["t"] = 'q';
	minsik_dict["u"] = 'r';
	minsik_dict["w"] = 's';
	minsik_dict["y"] = 't';
}

int main() {
	cin >> N; 
	// 초기화
	dict_init();

	// 민식어 만들기
	for (int n = 0; n < N; n++) {
		string cur;
		cin >> cur;
		origin_word.push_back(cur);
		int len = cur.length();
		string cur_minsik_word = "";
		for (int idx = 0; idx < len; idx++) {
			string c_to_str = "";
			if (cur[idx] == 'n'){
				if (idx + 1 < len && cur[idx+1] == 'g') {
					c_to_str = "ng";
					cur_minsik_word += minsik_dict[c_to_str];
					idx++;
				}
				else {
					c_to_str = "n";
					cur_minsik_word += minsik_dict[c_to_str];
				}
			} else {
				c_to_str += cur[idx];
				cur_minsik_word += minsik_dict[c_to_str];
			}
		}
		pq.push({ cur_minsik_word, n });
	}

	while (!pq.empty()) {
		cout << origin_word[pq.top().second] << endl;
		pq.pop();
	}

	return 0;
} 