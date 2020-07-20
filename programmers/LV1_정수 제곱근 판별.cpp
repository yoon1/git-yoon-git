#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    if (sqrt(n) - trunc(sqrt(n)) != 0)
        return -1;
    return pow(sqrt(n)+1, 2.0);
}