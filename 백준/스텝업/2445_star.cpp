#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;

	for (int i = 1; i <= 2 * N - 1; i++) {
		for (int j = 1; j <= 2 * N; j++) {
			if (i <= N && i >= j) printf("*");
			else if (i <= N && 2 * N - i < j) printf("*");
			else if (i > N && 2 * N - i >= j) printf("*");
			else if (i > N && i < j) printf("*");
			else printf(" ");
		}
		printf("\n");

	}
}