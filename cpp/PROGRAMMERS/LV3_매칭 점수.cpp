#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

struct Page{
	int idx; // index
	int basic, link; // 기본점수, 링크 수
	double score;// 나누기 연산이라 실수가 나올 수 있음. (score로 정렬할 것임)
};

bool comp(Page& a, Page& b) {
	if (a.score == b.score) return a.idx < b.idx;
	return a.score > b.score;
}
int solution(string word, vector<string> pages) { // keyword, pages
	int wsize = word.size();
	// 외부 링크가 어떤 페이지와 연관되는지 확인하기 위해서, 
	// 특정 url이 어떤 page의 인덱스를 갖고 있는지를 쉽게 확인하기 위해서 `HASH` - `MAP` 를 사용하자.
	map<string, int> pagehash;
	vector<Page> pagelist; // page 저장
	transform(word.begin(), word.end(), word.begin(), ::tolower); 
	// word의 string이 전부 tolowwer 가 된다.
	// transform을 이용하면 컨테이너의 시작과 끝을 줄 수 있고, 변환해서 써줘야 하는 container의 시작을 iterator를 줄 수 있다. 그리고 어떤 변화를 줄 지 function을 주면 된다.
	// namespace의 tolower를 사용
	for (int i = 0; i < pages.size(); i++) { // index가 필요하므로 i를 사용
		// parsing
		string& s = pages[i];// 자주 참조해야하므로 reference 변수로 사용
		transform(s.begin(), s.end(), s.begin(), ::tolower); // 소문자 변환

		// page url찾기
		int mid = 0, posl = 0, posr; 
		// position 을 찾은 다음 그 url을 찾아서 mid에 넣을건데 그 mid가 position l과 r사이에 있는지 본다.
		// mid : 해당 page의 url
		while (mid <= posl) { // meta tag안에 있는 url을 찾는 조건 
			posl = s.find("<meta", posl + 1); // 2번째 parameter를 찾을 시작점
			posr = s.find(">", posl); // 꺽쇄가 닫히는 점
			mid = s.rfind("https://");// 이 사이에 url이 있는지 찾기, 뒤에서 찾기(rfind)
			// position r사이에 있으면 우리가 원하는 url
			// 만약 mid가 posl보다 작으면 meta tag를 벗어나는 위치에 있기 때문에 다시 수행
		}
		posr = s.find("\"", mid);
		string url = s.substr(mid, posr - mid); //string의 substring으로 추출. size = (posr - mid)
		
		// 검색어 counting
		posl = s.find("<body>", posr);
		int basic = 0; // 기본점수
		for (int start = posl; ; ) { //시작은 body부터
			start = s.find(word, start + 1); // for문이 올때마다 진행하기 위해 1을 더한다.
			if (start == string::npos) 	break; // 코드에 해당하는 문자의 끝까지  왔다는 의미, 검색어를 찾았다.
			if (!isalpha(s[start - 1]) && !isalpha(s[start + wsize])) { // 문자열의 앞뒤를 확인(문자가 아닌 값이 오는지 안오는지)
				basic++;
				start += wsize;
			}
		}

		// 외부링크 수 구하기
		int link = 0;
		for (int start = posl; ;) {
			start = s.find("<a href", start + 1);
			if (start == string::npos) break;
			link++;
		}
		pagehash[url] = i; // index;
		pagelist.push_back({ i, basic, link, (double)basic});
	}

	// 링크 점수
	for (int i = 0; i < pages.size(); i++) {
		string& s = pages[i];
		for (int posl = 0, posr = 0; ; ) {
			posl = s.find("<a href", posr); // body앞쪽엔 하이퍼링크가 사용되지 않으므로 posr을 사용해도 무방
			if (posl == string::npos) break;// 하이퍼링크가 어떤 url을 링크하고있는지 url을 parsing해야 한다.

			posl = s.find("ttps://", posl); // 시작 위치가 pos l에 저장된다.
			posr = s.find("\"", posl); 
			string linkurl = s.substr(posl, posr - posl);
			// url에 해당하는 page index를 알아야 한다. 

			// 이걸 쉽게 찾을 수 있게 page hash에 넣어놨다.
			map<string, int>::iterator it = pagehash.find(linkurl);
			if (it != pagehash.end()) { // 검색값이 있음.
				pagelist[it->second].score += (double)pagelist[i].basic / pagelist[i].link;
				// 지금 페이지가 링크하고 있는 해당 페이지의 매칭 점수를 올려준다. 
			}
		}
	}
	sort(pagelist.begin(), pagelist.end(), comp);
	return pagelist.begin()->idx;
}

