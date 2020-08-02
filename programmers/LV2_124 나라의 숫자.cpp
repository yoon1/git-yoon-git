#include <iostream>
#include <string>
#include <vector>

using namespace std;


string solution(int n) {
	string answer = "";
	char a[3] = {'4','1','2'}; 
	while (n) {
		answer = a[n % 3] + answer;
		n = n / 3 - (!(n % 3));
	}
	return answer;
}
int main() {
	cout << solution(5) << endl;;
	cout << solution(6) << endl;;
	cout << solution(10) << endl;;
	return 0;
}
