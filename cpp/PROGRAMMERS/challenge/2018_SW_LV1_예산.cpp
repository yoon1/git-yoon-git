#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0, right  = 100000, left = 1, mid;
    while( left <= right) {
        bool flag = true;
        long long sum = 0;
        mid = (left + right) / 2;
        for(int budget : budgets) {
            if ( budget > mid) {
                sum += mid;
                flag = false;
            }
            else sum += budget;
        }
        if ( sum > M ) right = mid - 1;
        else {
            if ( flag ) 
                return *max_element(budgets.begin(), budgets.end());
            left = mid + 1;
            answer = mid;
        }
    }
	return answer;
}

int main() {
	cout << solution({100, 100, 100, 110}, 100) << endl;
	return 0;
}