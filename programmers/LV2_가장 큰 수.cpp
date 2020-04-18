#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(string a, string b) {
	
	if ((a + b).compare(b + a)) {
		cout << a + b << "," << b + a << endl;
		return (a + b) > (b + a);
	}
	return (a + b) < (b + a);
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> strNumbers;
	for (int i = 0; i < numbers.size(); i++) {
		strNumbers.push_back(to_string(numbers[i]));
	}
	sort(strNumbers.begin(), strNumbers.end(), compare);
	for (int i = 0; i < numbers.size(); i++) {
		answer += strNumbers[i] + " " ;
	}
	if (answer[0] == '0') return "0";
	return answer;
}

int main()
{
	
	//cout << solution({ 6,10,2 }) << endl;
	//cout << solution({ 3, 30, 34, 5, 9 }) << endl;
	cout << solution({ 3, 30 }) << endl;
	/* cout << solution({ 0,0,0,1000 }) << endl; 
	cout << solution({ 110,1,100 }) << endl;
	cout << solution({ 12,121}) << endl;
	cout << solution({ 121,21}) << endl;
	cout << solution({ 21,212}) << endl;
	cout << solution({ 212,21 }) << endl;
	cout << solution({ 0,0,1000,0}) << endl;
	cout << solution({ 10000,0,0,0 }) << endl;
	cout << solution({ 9,10,100,1000 }) << endl;
	cout << solution({ 0,1,101,1001,12,123}) << endl; 
	cout << solution({ 202,1,20,11,110,11,1}) << endl;
	cout << solution({ 93,93998769}) << endl; */
}
