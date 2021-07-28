#include <iostream>
#include <stdio.h>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <math.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef unsigned long long LL;
int N, K;
int judge(int Len) {
	int id = 1;
	for (int i = 2; i <= K; i++)
		id += (Len + 1);
	return id <= N;
}
int calc() {
	int ans, Left, Right, Mid;
	Left = 0;
	Right = N;
	while (Left <= Right) {
		Mid = (Left + Right) >> 1;
		if (judge(Mid)) {
			ans = Mid;
			Left = Mid + 1;
		}
		else
			Right = Mid - 1;
	}
	return ans;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << calc() << endl;
	}
	return 0;
}