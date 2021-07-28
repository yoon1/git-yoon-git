#include <iostream>
#include <list>
#include <string>

using namespace std;

list<char> ll;
int main() {
	// 초기값
	string str;
	int N;
	cin >> str;
	for (int i = 0; i < str.length(); i++) 
	{
		ll.push_back(str[i]);
	}
	
	// it 위치 
	auto it = ll.begin();
	while (it != ll.end()) it++;

	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		char op;
		cin >> op;
		switch (op)
		{
		case 'L':
			if (it != ll.begin()) 
				it--;
			break;
		case 'D':
			if (it != ll.end())
				it++;
			break;
		case 'B':
			if (it != ll.begin()) {
				it = ll.erase(--it);
			}
			break;
		case 'P':
			char c;
			cin >> c;
			ll.insert(it, c);
			break;
		default:
			break;
		}
	}
	for (auto it = ll.begin(); it != ll.end(); it++) 
	{
		cout << *it;
	}

	return 0;
}