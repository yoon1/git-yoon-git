#include <iostream>
#define MAX 100000

using namespace std;

int main() {
	char charA[MAX+1] = {};
	char charB[MAX+1] = {};
	int A[MAX] = { 0 };
	int B[MAX] = { 0 };

	scanf("%s %s", charA, charB);
	for (int i = 0; i < MAX; i++) {
		A[i] = charA[i] - '0';
		B[i] = charB[i] - '0';
	}


	for (int i = 0; i < MAX; i++) printf("%d", (A[i] & B[i])); printf("\n");
	for (int i = 0; i < MAX; i++) printf("%d", (A[i] | B[i])); printf("\n");
	for (int i = 0; i < MAX; i++) printf("%d", (A[i] ^ B[i])); printf("\n");
	for (int i = 0; i < MAX; i++) printf("%d", !A[i]); printf("\n");
	for (int i = 0; i < MAX; i++) printf("%d", !B[i]); printf("\n");

	return 0;
}