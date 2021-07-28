#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

class mycomparision {
	bool reverse;
public :
	mycomparision(const bool& revparam = false)
	{
		reverse = revparam;
	}
	bool operator() (const int& lhs, const int&rhs) const
	{
		if (reverse) return (lhs > rhs);
		else return (lhs < rhs);
	}

};
int main() {
	int myints[] = { 10,60,50,20 };

	priority_queue<int> first;
	priority_queue<int> second(myints, myints + 4);
	priority_queue<int, vector<int>, greater<int> > third(myints, myints + 4);
	typedef priority_queue<int, vector<int>, mycomparision> mypd_type;

	mypd_type fourth;
	mypd_type fifth(mycomparision(true));

	for (int i = 0; i < first.size(); i++) {
		cout << fifth.top();
	}

	return 0;
}

