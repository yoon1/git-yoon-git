#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> food_times, long long k) {
	long long sum = 0, before = 0;  //�հ� ������ �����
	priority_queue<pair<int, int>> pfood_times; //�켱���� ť
	//�켱���� ť�� �ű�鼭 ��Ȯ��(min heap�� ���� -�� ����)
	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
		pfood_times.push(make_pair(-food_times[i], (i + 1)));
	}//�ѽð��� K���� ���ų� ���ٸ� -1�� ����
	if (sum <= k)    return -1;
	//���� ���ĸ�ŭ �ð��� �ҿ��ϴµ� �ɸ��� �ð��� (���� �������� ���� - �������İ� * �� ���İ���) �̴�.
	//�� �ð���ŭ K�����ְ� ���ĵ� ����.(����Ҷ� -�־�� �����´�)
	while ((-pfood_times.top().first - before) * pfood_times.size() <= k) {
		k -= (-pfood_times.top().first - before) * pfood_times.size();
		before = -pfood_times.top().first;
		pfood_times.pop();
	}//�ݺ����� �����ٸ� ������� �ľ��Ѵ�.
	vector<pair<int, int>> ftimes;
	//���� �ľ��� ���� vector�� �ű��.
	while (!pfood_times.empty()) {
		//���� ���Լ��� ����� �������ϱ� pair�� �������ش�.
		ftimes.push_back(make_pair(pfood_times.top().second, -pfood_times.top().first));
		pfood_times.pop();
	}
	//���� ������� �����Ѵ�.
	sort(ftimes.begin(), ftimes.end());
	//������ �������� ��ġã�� ��ȯ
	return ftimes[k % ftimes.size()].first;
}


void print(vector<int> food_times, long long k, int answer) {
	int t = solution(food_times, k);
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

int main() {
	print({ 3,1,2 }, 5, 1);
	print({ 8,6,4 }, 15, 2);
	print({ 946, 314, 757, 322, 559, 647, 983, 482, 145 }, 1833, 1);

	return 0;
}