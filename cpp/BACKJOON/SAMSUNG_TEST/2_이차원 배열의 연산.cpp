#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, K;
int cr, cc;
// K : ��ǥ��
int arr[105][105];

// ����
void operator_r() { 
	int max_val = 0;
	int nums[205]; // ���� ������ Ƚ�� 
	int t_arr[105][105]; // �����
	memset(t_arr, 0, sizeof(t_arr)); // 0���� �ʱ�ȭ

	for (int i = 0; i < cr; i++) { // ���� ���, R������ �����Ѵٸ�? ( 1����� ~ ��������)
		memset(nums, 0, sizeof(nums));
		vector<pair<int, int>> v;
		
		for (int j = 0; j < cc; j++) // (1�� ~ ��������)
			nums[arr[i][j]]++; // Ƚ�� ����

		for (int j = 1; j < 205; j++) {
			if (nums[j] == 0) continue; // 0�� ���°� �� �ʿ䵵 ����, ���⼭ map�� ���� �͵� ����ϵ�.
			v.push_back({ nums[j], j }); // ������ �����ؾ���
		}

		sort(v.begin(), v.end()); // sorting(Ƚ���� ���ڸ� sorting��, ���� cmp�� �������ֱ� �������Ƿ� �տ� Ƚ���� ����)

		int idx = 0;
		//for (auto &j : v) {
		for(vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++){
			t_arr[i][idx++] = it->second; // �ι�° ���� ���� �ְ�(��� ����)
			if (idx == 100) break;
			t_arr[i][idx++] = it->first;  // ù��° ���� ����(Ƚ��)
			if (idx == 100) break;
		}
		max_val = max(max_val, idx); // ū ��?
	}
	
	//(flag) ? cc : cr = max_val; // ���� ū ��?
	cc = max_val;
	memcpy(arr, t_arr, sizeof(arr));
}

// ����
void operator_c() { 
	int max_val = 0;
	int nums[205]; // ���� ������ Ƚ�� 
	int t_arr[105][105]; // �����
	memset(t_arr, 0, sizeof(t_arr)); // 0���� �ʱ�ȭ

	for (int j = 0; j < cc; j++) { // ���� ���, R������ �����Ѵٸ�? ( 1����� ~ ��������)
		memset(nums, 0, sizeof(nums));
		vector<pair<int, int>> v;

		for (int i = 0; i < cr; i++) // (1�� ~ ��������)
			nums[arr[i][j]]++; // Ƚ�� ����

		for (int i = 1; i < 205; i++) {
			if (nums[i] == 0) continue; // 0�� ���°� �� �ʿ䵵 ����, ���⼭ map�� ���� �͵� ����ϵ�.
			v.push_back({ nums[i], i}); // ������ �����ؾ���
		}

		sort(v.begin(), v.end()); // sorting(Ƚ���� ���ڸ� sorting��, ���� cmp�� �������ֱ� �������Ƿ� �տ� Ƚ���� ����)

		int idx = 0;
		//for (auto &j : v) {
		for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
			t_arr[idx++][j] = it->second; // �ι�° ���� ���� �ְ�(��� ����)
			if (idx == 100) break;
			t_arr[idx++][j] = it->first;  // ù��° ���� ����(Ƚ��)
			if (idx == 100) break;
		}
		max_val = max(max_val, idx); // ū ��?
	}

	//(flag) ? cc : cr = max_val; // ���� ū ��?
	cr = max_val;
	memcpy(arr, t_arr, sizeof(arr));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// input
	cin >> R >> C >> K; 
	R-- , C--;

	cr = 3, cc = 3;
	for (int i = 0; i < cr; i++)
		for (int j = 0; j < cc; j++)
			cin >> arr[i][j];

	for(int time = 0; time <= 100; time++) {
		//  ��ǥ�� ����
		if (arr[R][C] == K) {
			cout << time << endl;
			return 0;
		}
		if (cr >= cc) operator_r(); // (���ǰ��� >= ���� ����)
		else operator_c(); // (���ǰ��� < ���� ����)
	}
	cout << "-1";
		
	return 0;
}