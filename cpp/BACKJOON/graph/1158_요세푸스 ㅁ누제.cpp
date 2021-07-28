#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;
vector<int> answer;
int main() {
	cin >> N >> K;
	// v �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}

	// target index�� �ʱⰪ
	int target = 0;

	// N �� �ݺ�
	for (int i = 0; i < N; i++) {
		target += K - 1;
		if (target >= v.size())
		{
			target = target % v.size();
		}
		answer.push_back(v[target]);
		v.erase(v.begin() + target);
	}

	// v ���
	cout << "<";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i];
		if (i != answer.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";
	
	return 0;
}