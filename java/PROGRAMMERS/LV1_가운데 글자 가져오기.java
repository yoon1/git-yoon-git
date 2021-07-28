import java.util.*;
class Solution {
    public String solution(String s) {
        int len = s.length();
        int lenDiv2 = len / 2;
        if ( len % 2 == 0 )
            return s.substring(lenDiv2-1, lenDiv2+1);
        else
            return s.substring(lenDiv2, lenDiv2+1);
    }
}
// 01234 --> 5 / 2 = 2 -> substr(2,1) 
// 0123 --> 4 / 2 = 2 -> substr(2-1,2)