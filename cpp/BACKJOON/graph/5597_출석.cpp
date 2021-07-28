#include <iostream>
#define STUDENT 30

using namespace std;

bool students[STUDENT] = { false };
int main() {
	for (int i = 1; i <= STUDENT - 2; i++)
	{
		int num; cin >> num;
		students[num] = true;
	}

	for (int i = 1; i <= STUDENT; i++)
	{ 
		if (!students[i]) cout << i << "\n";
	}

	return 0;
}