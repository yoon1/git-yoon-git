#include <iostream>

using namespace std;

int solution(int n)
{
	int sum = 0;
	while (n > 0)
	{
		cout << "������ n : "  << n << endl;
		sum += n % 10;
		cout << "sum : " << sum << endl;
		n /= 10; 
		cout << "������ n : " << n << endl;

	}
	return sum;
}

int main() {
	
	cout << solution(123) << endl;
	return 0;
}