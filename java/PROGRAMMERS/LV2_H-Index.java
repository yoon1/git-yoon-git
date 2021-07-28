import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        for(int i=0; i < citations.length; i++){
            int p1 = Math.min(i+1, citations[i]);
            int p2 = 0;
            for(int j = 0; j < citations.length; j++){
                if ( citations[j] >= p1) {
                    p2 = citations.length - j ;
                    break;
                }
            }
            answer = Math.max(answer, Math.min(p1, p2));
        }
        return answer;
    }
}