#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numOne(int n) {
    int count = 0;
    while(n > 1) {
        if ( n % 2 == 1 ) count++;
        n = n / 2;
    }
    return count;
}
int solution(int n) {
    int bigNumber = n;
    while(1) {
        bigNumber++;
        if ( numOne(n) == numOne(bigNumber) ) 
            break;
    } 
    return bigNumber;
}