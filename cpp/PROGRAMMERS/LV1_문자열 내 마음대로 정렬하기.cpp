#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    int len = strings[0].length();
    for(int i=0; i < strings.size(); i++){
        for(int j=0; j < strings.size(); j++){
            if ( strings[i][n] < strings[j][n])
                swap(strings[i] , strings[j]);
            else if ( strings[i][n] == strings[j][n])
                if ( strings[i] < strings[j])
                    swap(strings[i] , strings[j]);
        }
    }
    return strings;
}