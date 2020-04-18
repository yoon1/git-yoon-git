#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int M = key.size();
	int N = lock.size();
	vector<int> key_state[30];
	vector<int> lock_state[90];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < key[i].size(); j++) {
			if (key[i][j] == 1)
				key_state[i].push_back(j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < lock[i].size(); j++) {
			if (lock[i][j] == 0)
				lock_state[i+M-1].push_back(j+M-1);
		}
	}
	
	/* 90�� ȸ�� */
	for (int r = 0; r< 1; r++) {
		vector<int> temp_key_state[30];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < key_state[i].size(); j++) {
				temp_key_state[key_state[i][j]].push_back(M - 1 - i);
			}
		}

		// copy~ 
		for (int i = 0; i < N; i++) {
			key_state[i] = temp_key_state[i];
		}
		
		for (int row = 0; row < 2 * M + N - 3; row++) {
			// �̵�
			// ���� Ű �����
			vector<int> current_key[90];
			for (int col = 0; col < 2 * M + N - 3; col++) {
				for (int i = 0; i < 30; i++) {
					for (int j = 0; j < key_state[i].size(); j++) {
						if (M - 1 <= key_state[i][j] + col && M - 1 + N - 1 >= key_state[i][j] + col
							&& M - 1 <= i + row && M - 1 + N - 1 >= i + row) { 
							current_key[i + row].push_back(key_state[i][j] + col);
						}
					}
				}
				answer = true;
				for (int i = 0; i < 30; i++) {
					if (current_key[i] != lock[i]) {
						answer = false;
						break;
					}
				}
				if (answer) {
					return answer;
				}
			}
		}
	}
	return answer;
}

int main() {
	cout << solution({{0, 0, 0}, { 1, 0, 0 }, { 0, 1, 1 }} , {{1, 1, 1}, { 1, 1, 0 }, { 1, 0, 1 }}) << endl;
	
	return 0;
}