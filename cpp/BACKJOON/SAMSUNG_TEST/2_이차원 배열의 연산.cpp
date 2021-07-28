#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, K;
int cr, cc;
// K : 목표값
int arr[105][105];

// 연산
void operator_r() { 
	int max_val = 0;
	int nums[205]; // 숫자 나오는 횟수 
	int t_arr[105][105]; // 연산용
	memset(t_arr, 0, sizeof(t_arr)); // 0으로 초기화

	for (int i = 0; i < cr; i++) { // 예를 들어, R연산을 적용한다면? ( 1행부터 ~ 마지막행)
		memset(nums, 0, sizeof(nums));
		vector<pair<int, int>> v;
		
		for (int j = 0; j < cc; j++) // (1열 ~ 마지막열)
			nums[arr[i][j]]++; // 횟수 증가

		for (int j = 1; j < 205; j++) {
			if (nums[j] == 0) continue; // 0번 나온건 볼 필요도 없음, 여기서 map을 쓰는 것도 방법일듯.
			v.push_back({ nums[j], j }); // 쌍으로 저장해야함
		}

		sort(v.begin(), v.end()); // sorting(횟수와 숫자를 sorting함, 굳이 cmp를 구현해주기 귀찮으므로 앞에 횟수를 넣음)

		int idx = 0;
		//for (auto &j : v) {
		for(vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++){
			t_arr[i][idx++] = it->second; // 두번째 값을 먼저 넣고(결과 숫자)
			if (idx == 100) break;
			t_arr[i][idx++] = it->first;  // 첫번째 값을 넣음(횟수)
			if (idx == 100) break;
		}
		max_val = max(max_val, idx); // 큰 수?
	}
	
	//(flag) ? cc : cr = max_val; // 가장 큰 수?
	cc = max_val;
	memcpy(arr, t_arr, sizeof(arr));
}

// 연산
void operator_c() { 
	int max_val = 0;
	int nums[205]; // 숫자 나오는 횟수 
	int t_arr[105][105]; // 연산용
	memset(t_arr, 0, sizeof(t_arr)); // 0으로 초기화

	for (int j = 0; j < cc; j++) { // 예를 들어, R연산을 적용한다면? ( 1행부터 ~ 마지막행)
		memset(nums, 0, sizeof(nums));
		vector<pair<int, int>> v;

		for (int i = 0; i < cr; i++) // (1열 ~ 마지막열)
			nums[arr[i][j]]++; // 횟수 증가

		for (int i = 1; i < 205; i++) {
			if (nums[i] == 0) continue; // 0번 나온건 볼 필요도 없음, 여기서 map을 쓰는 것도 방법일듯.
			v.push_back({ nums[i], i}); // 쌍으로 저장해야함
		}

		sort(v.begin(), v.end()); // sorting(횟수와 숫자를 sorting함, 굳이 cmp를 구현해주기 귀찮으므로 앞에 횟수를 넣음)

		int idx = 0;
		//for (auto &j : v) {
		for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
			t_arr[idx++][j] = it->second; // 두번째 값을 먼저 넣고(결과 숫자)
			if (idx == 100) break;
			t_arr[idx++][j] = it->first;  // 첫번째 값을 넣음(횟수)
			if (idx == 100) break;
		}
		max_val = max(max_val, idx); // 큰 수?
	}

	//(flag) ? cc : cr = max_val; // 가장 큰 수?
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
		//  목표값 도달
		if (arr[R][C] == K) {
			cout << time << endl;
			return 0;
		}
		if (cr >= cc) operator_r(); // (행의갯수 >= 열의 갯수)
		else operator_c(); // (행의갯수 < 열의 갯수)
	}
	cout << "-1";
		
	return 0;
}