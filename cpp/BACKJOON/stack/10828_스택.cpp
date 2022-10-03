#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

int main() {
    int n;
    string input;
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        // split
        if (input.compare("push") == 0) {
            int num;
            cin >> num;
            stk.push(num);
        } else if (input.compare("pop") == 0) {
            if (stk.empty()) {
                cout << "-1\n";
            } else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        } else if (input.compare("size") == 0) {
            cout << stk.size() << '\n';
        } else if (input.compare("empty") == 0) {
            cout << stk.empty() << '\n';
        } else if (input.compare("top") == 0) {
            if (stk.empty()) {
                cout << "-1\n";
            } else {
                cout << stk.top() << '\n';
            }
        }
    }

    return 0;
}