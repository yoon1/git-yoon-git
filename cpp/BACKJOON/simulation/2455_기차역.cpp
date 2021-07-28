#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int down, up; 
	int max_people = 0;
	int cur_people = 0;
	for(int i=0; i < 4; i++) {
		cin >> down >> up;
		cur_people -= down; 
		cur_people += up;
		max_people = max(max_people, cur_people);
	}
	cout << max_people << endl;
}