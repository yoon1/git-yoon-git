#include <iostream>
#include <algorithm>

using namespace std;

int N, W, H, L;
int main() {
	cin >> N >> W >> H >> L;
	cout << min(N, (W / L) * (H / L)) << endl;

	return 0;
}