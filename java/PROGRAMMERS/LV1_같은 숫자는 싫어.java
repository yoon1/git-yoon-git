import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        int cur = 0;
        for(int i = 0 ; i < arr.length; i++){
            if ( list.isEmpty() || cur != arr[i]) {
                list.add(arr[i]);
                cur = arr[i];
            }
        }
        int[] answer = new int[list.size()];
        int index = 0;
        for(int i=0; i < list.size(); i++){
            answer[index++] = list.get(i);
        }
        return answer;
    }
}