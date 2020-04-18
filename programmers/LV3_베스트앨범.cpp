#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string>genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;
	map<string, vector< pair<int, int>>> v;

	for (int i = 0; i < genres.size(); i++) {
		const auto & genre = genres[i];
		const auto & play = plays[i];
		m[genre] = (m.find(genre) == m.end()) ? 0 : m[genre];
		m[genre] += play;
		v[genre] = (v.find(genre) == v.end()) ? vector< pair<int, int>>() : v[genre];
		v[genre].push_back(make_pair(play, i));
	} 
	vector< pair<string, int>> genreSort;

	for (const auto & elem : m) {
		genreSort.push_back(elem);
	}

	sort(genreSort.begin(), genreSort.end(), [](pair<string, int> x, pair<string, int> y) {
		return x.second >= y.second;
	});

	for (const auto & elem : genreSort) {
		string genre = elem.first;
		sort(v[genre].begin(), v[genre].end(), [](pair<int, int> x, pair<int, int>y) {
			if (x.first == y.first) {
				return x.second < y.second;
			}
			return x.first >= y.first;
		});
		int idx = 0;
		for (const auto & p : v[genre]) {
			if (idx >= 2) {
				break;
			}
			answer.push_back(p.second);
			idx += 1;
		}
	}

	return answer;
}