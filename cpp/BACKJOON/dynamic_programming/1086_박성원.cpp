#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll d[1 << 15][101]; // d[i][j] : i�� ����� ����, �������� j�� ���� ��. �ʱⰪ�� 0.
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	int n; cin >> n;
	vector<string> num(n);
	vector<int> a(n);   //i��° ���� k��ⷯ��
	vector<int> len(n); //i��° ���� ����
	for (int i = 0; i < n; i++) {
		cin >> num[i]; // ���ڿ��� �Է� ����.
		len[i] = num[i].size(); // ���ڿ��� �� ���̸� �Է¹���.
	}
	int k; 
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len[i]; j++) { // a[i] num[i]�� ���� ���� ����(K�� 100���� ���� �� �̹Ƿ� int������ �����ص� �����)
			a[i] = a[i] * 10 + (num[i][j] - '0'); 
			a[i] %= k;
		}
	}
	vector<int> ten(51);  // 10�� i���� k��ⷯ��
	ten[0] = 1;
	for (int i = 1; i <= 50; i++) { 
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}

	d[0][0] = 1; // 0�� 0���� ��
	for (int i = 0; i < (1 << n); i++) { // 0 ~ 2^n (all bits : ��� ����� ��. 0���� �������ȱ� 0�� �������� ����)
		for (int j = 0; j < k; j++) { // �������� �ϴ� �� ( �ִ� 100 )
			for (int l = 0; l < n; l++) { // num ����
				if ((i & (1 << l)) == 0) { // ���� ���� ���� ���� ���? (1�� ���� ���� �ٲ� �ʿ䰡����)
					int next = j * ten[len[l]]; // ���� = (�������� �ϴ� ��) * ten[���� �� 10�� i���� ��ⷯ��];
					next %= k; // next %= k;
					next += a[l]; // next�� l��° ���� ���Ѵ�.
					next %= k; // next�� k�� ���� ���� ���� ���Ѵ�.
					// next = [ (j*ten(len(l))) % k + a(l)%k ] % k
					d[i | (1 << l)][next] += d[i][j]; 
					// d[�ش� ��Ʈ�� ������ ��(set)][�����ȣ] += d[������ ���][�������� �ϴ� ��];
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
