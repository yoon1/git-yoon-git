import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int[] giveUpper1 = {1,2,3,4,5};
        int[] giveUpper2 = {2,1,2,3,2,4,2,5};
        int[] giveUpper3 = {3,3,1,1,2,2,4,4,5,5};
        int[] okCount = new int[3];
        int maxCount = 0;
        ArrayList<Integer> li = new ArrayList<Integer>();
        
        for(int i=0; i < answers.length; i++){
            if ( giveUpper1[i % 5] == answers[i]) {okCount[0]++;}
            if ( giveUpper2[i % 8] == answers[i]) {okCount[1]++;}
            if ( giveUpper3[i % 10] == answers[i]) {okCount[2]++;}
        }
        for(int i=0 ; i < 3; i++){
            if ( okCount[i] > maxCount)
                maxCount = okCount[i];
        }

        for(int i=0; i < 3; i++) {
            if ( okCount[i] == maxCount ){
                li.add(i+1);
            }
        }
        
        answer = new int[li.size()];
        for(int i = 0; i < answer.length; i++){
            answer[i] = li.get(i);
        }
        
        return answer;
    }
}