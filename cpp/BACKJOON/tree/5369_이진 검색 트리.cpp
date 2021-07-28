#include <iostream>
#include <algorithm>
using namespace std;

int arr[10010], n;

void solve(int l, int r) {
	if (l > r) return;
	int root = l;
	int s = l, e = r;
	while (arr[s] >= arr[root]) s++; // left child
	while (arr[e] > arr[root]) e--; // right child
	solve(s, e);
	solve(e + 1, r);
	printf("%d\n", arr[root]);
}
int main() {
	ios_base::sync_with_stdio(false);
	int x;
	while (cin >> x) 
		arr[n++] = x;
	solve(0, n - 1);
}
