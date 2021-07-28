#include <iostream>

using namespace std;

int N;
int winA = 0, winB = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int A, B; cin >> A >> B;
		if (A > B) winA++;
		else if(A < B) winB++;
	}
	cout << winA << " " << winB;
	
	return 0;
}