#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 10

using namespace std;
int arr[MAX] = { 0 };
map<int, int> m;

void solution(int idx, int sum) 
{
	int val = abs(sum - 100);
	if (m.find(val) != m.end() || m[val] < sum)
		m[abs(sum - 100)] = sum;
	if (idx == MAX - 1) return;
	solution(idx + 1, sum + arr[idx+1]);
}

int main() {
	// input
	for (int i = 0 ; i < 10; i++) 
		cin >> arr[i];

	solution(0, arr[0]);
	cout << m.begin()->second << endl;

	return 0;
}



void solution()
{
	int sum = 0;
	for (int i = 0; i < 10; i++) 
	{
		if ( abs(sum + arr[i] - 100) <= abs(sum - 100)) 
			sum += arr[i];
	}

	printf("%d", sum);
}