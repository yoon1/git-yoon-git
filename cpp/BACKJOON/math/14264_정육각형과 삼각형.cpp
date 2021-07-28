#include <iostream>
#include <math.h>

using namespace std; 

int N;
int main() {
	cin >> N;
	printf("%.10f", (double)N * (double)N * sqrt(3.0) * 0.25);
	return 0;
}