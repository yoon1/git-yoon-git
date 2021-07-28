#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

struct Page{
	int idx; // index
	int basic, link; // �⺻����, ��ũ ��
	double score;// ������ �����̶� �Ǽ��� ���� �� ����. (score�� ������ ����)
};

bool comp(Page& a, Page& b) {
	if (a.score == b.score) return a.idx < b.idx;
	return a.score > b.score;
}
int solution(string word, vector<string> pages) { // keyword, pages
	int wsize = word.size();
	// �ܺ� ��ũ�� � �������� �����Ǵ��� Ȯ���ϱ� ���ؼ�, 
	// Ư�� url�� � page�� �ε����� ���� �ִ����� ���� Ȯ���ϱ� ���ؼ� `HASH` - `MAP` �� �������.
	map<string, int> pagehash;
	vector<Page> pagelist; // page ����
	transform(word.begin(), word.end(), word.begin(), ::tolower); 
	// word�� string�� ���� tolowwer �� �ȴ�.
	// transform�� �̿��ϸ� �����̳��� ���۰� ���� �� �� �ְ�, ��ȯ�ؼ� ����� �ϴ� container�� ������ iterator�� �� �� �ִ�. �׸��� � ��ȭ�� �� �� function�� �ָ� �ȴ�.
	// namespace�� tolower�� ���
	for (int i = 0; i < pages.size(); i++) { // index�� �ʿ��ϹǷ� i�� ���
		// parsing
		string& s = pages[i];// ���� �����ؾ��ϹǷ� reference ������ ���
		transform(s.begin(), s.end(), s.begin(), ::tolower); // �ҹ��� ��ȯ

		// page urlã��
		int mid = 0, posl = 0, posr; 
		// position �� ã�� ���� �� url�� ã�Ƽ� mid�� �����ǵ� �� mid�� position l�� r���̿� �ִ��� ����.
		// mid : �ش� page�� url
		while (mid <= posl) { // meta tag�ȿ� �ִ� url�� ã�� ���� 
			posl = s.find("<meta", posl + 1); // 2��° parameter�� ã�� ������
			posr = s.find(">", posl); // ���Ⱑ ������ ��
			mid = s.rfind("https://");// �� ���̿� url�� �ִ��� ã��, �ڿ��� ã��(rfind)
			// position r���̿� ������ �츮�� ���ϴ� url
			// ���� mid�� posl���� ������ meta tag�� ����� ��ġ�� �ֱ� ������ �ٽ� ����
		}
		posr = s.find("\"", mid);
		string url = s.substr(mid, posr - mid); //string�� substring���� ����. size = (posr - mid)
		
		// �˻��� counting
		posl = s.find("<body>", posr);
		int basic = 0; // �⺻����
		for (int start = posl; ; ) { //������ body����
			start = s.find(word, start + 1); // for���� �ö����� �����ϱ� ���� 1�� ���Ѵ�.
			if (start == string::npos) 	break; // �ڵ忡 �ش��ϴ� ������ ������  �Դٴ� �ǹ�, �˻�� ã�Ҵ�.
			if (!isalpha(s[start - 1]) && !isalpha(s[start + wsize])) { // ���ڿ��� �յڸ� Ȯ��(���ڰ� �ƴ� ���� ������ �ȿ�����)
				basic++;
				start += wsize;
			}
		}

		// �ܺθ�ũ �� ���ϱ�
		int link = 0;
		for (int start = posl; ;) {
			start = s.find("<a href", start + 1);
			if (start == string::npos) break;
			link++;
		}
		pagehash[url] = i; // index;
		pagelist.push_back({ i, basic, link, (double)basic});
	}

	// ��ũ ����
	for (int i = 0; i < pages.size(); i++) {
		string& s = pages[i];
		for (int posl = 0, posr = 0; ; ) {
			posl = s.find("<a href", posr); // body���ʿ� �����۸�ũ�� ������ �����Ƿ� posr�� ����ص� ����
			if (posl == string::npos) break;// �����۸�ũ�� � url�� ��ũ�ϰ��ִ��� url�� parsing�ؾ� �Ѵ�.

			posl = s.find("ttps://", posl); // ���� ��ġ�� pos l�� ����ȴ�.
			posr = s.find("\"", posl); 
			string linkurl = s.substr(posl, posr - posl);
			// url�� �ش��ϴ� page index�� �˾ƾ� �Ѵ�. 

			// �̰� ���� ã�� �� �ְ� page hash�� �־����.
			map<string, int>::iterator it = pagehash.find(linkurl);
			if (it != pagehash.end()) { // �˻����� ����.
				pagelist[it->second].score += (double)pagelist[i].basic / pagelist[i].link;
				// ���� �������� ��ũ�ϰ� �ִ� �ش� �������� ��Ī ������ �÷��ش�. 
			}
		}
	}
	sort(pagelist.begin(), pagelist.end(), comp);
	return pagelist.begin()->idx;
}

