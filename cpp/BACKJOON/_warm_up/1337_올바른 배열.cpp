/* ¹Ý·Ê : 
3
1
3
5
output:4
answer:2
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int t; cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	
	int maxCount = 1;
	int curCount = 1;
	for (int i = 1; i < v.size(); i++) 
	{
		if (v[i] == v[i - 1] + 1) 
		{
			curCount++;
			maxCount = max(maxCount, curCount);
			if (maxCount == 5)
			{
				cout << 0;
				return 0;
			}
		}
		else
		{
			curCount = 1;
		}
	}
	cout << 5 - maxCount;
	return 0;
}