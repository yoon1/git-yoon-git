#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll d[1 << 15][101]; // d[i][j] : i를 골랐으 ㄹ때, 나머지가 j인 것의 수. 초기값은 0.
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	int n; cin >> n;
	vector<string> num(n);
	vector<int> a(n);   //i번째 수의 k모듈러값
	vector<int> len(n); //i번째 수의 길이
	for (int i = 0; i < n; i++) {
		cin >> num[i]; // 문자열로 입력 받음.
		len[i] = num[i].size(); // 문자열의 각 길이를 입력받음.
	}
	int k; 
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len[i]; j++) { // a[i] num[i]의 정수 값을 저장(K는 100보다 작은 수 이므로 int형으로 저장해도 충분함)
			a[i] = a[i] * 10 + (num[i][j] - '0'); 
			a[i] %= k;
		}
	}
	vector<int> ten(51);  // 10의 i승의 k모듈러값
	ten[0] = 1;
	for (int i = 1; i <= 50; i++) { 
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}

	d[0][0] = 1; // 0을 0으로 나
	for (int i = 0; i < (1 << n); i++) { // 0 ~ 2^n (all bits : 모든 경우의 수. 0부터 시작했읜깐 0을 기준으로 포함)
		for (int j = 0; j < k; j++) { // 나누고자 하는 값 ( 최대 100 )
			for (int l = 0; l < n; l++) { // num 갯수
				if ((i & (1 << l)) == 0) { // 아직 포함 되지 않은 경우? (1일 때는 굳이 바꿀 필요가없음)
					int next = j * ten[len[l]]; // 다음 = (나누고자 하는 값) * ten[길이 및 10의 i승의 모듈러값];
					next %= k; // next %= k;
					next += a[l]; // next에 l번째 수를 더한다.
					next %= k; // next에 k를 나눈 모듈라 값을 더한다.
					// next = [ (j*ten(len(l))) % k + a(l)%k ] % k
					d[i | (1 << l)][next] += d[i][j]; 
					// d[해당 비트를 포함한 값(set)][모듈라번호] += d[현재의 경우][나누고자 하는 값];
				}
			}
		}
	}
	ll t1 = d[(1 << n) - 1][0];
	ll t2 = 1;
	for (ll i = 2; i <= n; i++) t2 *= i;
	ll g = gcd(t1, t2);
	t1 /= g;
	t2 /= g;
	cout << t1 << '/' << t2 << '\n';
}
