#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int arr[64][64];

string solve(int y, int x, int n, int p)
{
	if (n == 1)
	{
		string res = "";
		res += to_string(arr[y][x]);
		return res;
	}

	string first = "";
	first += to_string(arr[y][x]);
	string lu = solve(y, x, n / 2, p / 2);
	string ru = solve(y, x + p, n / 2, p / 2);
	string ld = solve(y + p, x, n / 2, p / 2);
	string rd = solve(y + p, x + p, n / 2, p / 2);

	if (lu == first && ru == first && ld == first && rd == first)
		return first;

	return '(' + lu + ru + ld + rd + ')';
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);

	cout << solve( 0, 0, n, n / 2);

	return 0;
}


