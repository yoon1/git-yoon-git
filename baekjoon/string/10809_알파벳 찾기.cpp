#include <iostream>
#include <memory.h>
using namespace std;

int alpha[26];
int main() {
	
	char c;
	int i = 0; 
	memset(alpha, -1, sizeof(alpha));

	while (cin.get(c)) {
		if (c == '\n') break;
		if (alpha[(int)(c - 97)] == -1) {
			alpha[(int)(c - 97)] = i;
		}
		i++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}

	return 0;
}
