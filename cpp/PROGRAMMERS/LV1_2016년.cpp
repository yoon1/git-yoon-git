#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int day_num[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31}; 
    string day_week[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int total_day = 5; // ±›ø‰¿œ
    for(int i=0; i < a; i++){
        total_day += day_num[i];
    }
    total_day += b - 1;
    return day_week[total_day%7];;
}