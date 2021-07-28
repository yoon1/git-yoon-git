import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int [] student = new int [n+1];
        Arrays.fill(student, 1);
        
        for(int i=0; i < lost.length; i++){
            student[lost[i]]--;
        }
        for(int i=0; i < reserve.length; i++){
            student[reserve[i]]++;
        }
        for(int i=1; i< student.length; i++){
            if ( student[i] == 0) {
                if(i-1 >= 0 && student[i-1] >= 2) {
                    answer++;
                    student[i-1]--;
                    continue;
                }
                if ( i + 1 < student.length && student[i+1] >= 2 ){
                    answer++;
                    student[i+1]--;
                    continue;
                    
                }
            }
            else answer++;
        }
        return answer;
    }
}