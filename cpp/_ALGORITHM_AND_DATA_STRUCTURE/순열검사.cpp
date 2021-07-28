#include <vector>
#include <iostream>
#define MAX 100000

using namespace std;

bool solution(vector<int> arr) {
	bool answer = true;
	bool a[MAX+1] = { false,};
//	cout << "arr.size : " << arr.size() << endl;

	for (int i = 0; i < arr.size() ; i++) {
		if(arr[i] <= arr.size()){
			a[arr[i]] = true;
			//cout << "arr[" << i << "]: " << arr[i] << endl;
		}
		
	}
	for (int i = 1; i <= arr.size(); i++) {
		if (a[i] == false) {
			answer = false;
			break; 
		}
	}
	return answer;
}
int main() {
	vector<int> a = { 4, 1, 3, 5 };

	cout << solution(a) << endl;

}