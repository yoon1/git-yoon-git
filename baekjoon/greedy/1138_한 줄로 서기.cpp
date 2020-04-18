#include <iostream>

using namespace std;

int person[10] = { 0 };
int result[10] = { 0 };
int main() {
	std::ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N;

	
	for (int i = 0; i < N; i++) {
		cin >> K;
		person[i] = K;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0, count = 0; j < N; j++) {
			if (result[j] == 0) { 
				if (person[i] == count) {
					result[j] = i + 1;
				}
					count++;
			}
		}
	}
	
	for (int i = 0; i < N ; i++) {
		cout << result[i] << " ";
	}
	
	return 0;
}