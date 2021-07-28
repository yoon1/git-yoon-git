import java.util.*;
import static java.lang.String.join;

class Solution {
    public String solution(String s) {
        String[] strs = s.split("");
        Arrays.sort(strs, Comparator.reverseOrder());
        return join("",strs);
    }
}