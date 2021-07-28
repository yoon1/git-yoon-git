import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        //ArrayList<String> strNumbers = new ArrayList<String>();
        String[] strNumbers = new String[numbers.length];
        for(int i=0; i < numbers.length; i++){
            //strNumbers.add(toString(numbers[i]));
            strNumbers[i] = Integer.toString(numbers[i]);
        }
        Arrays.sort(strNumbers, new Mycomp());
        for(int i=0; i < strNumbers.length; i++){
            answer += strNumbers[i];
        }
        if(answer.startsWith("0")) return "0";
        return answer;
    }
    
    // 내림차순?
    class Mycomp implements Comparator<String> {
        public int compare(String a, String b) {
            return (b + a).compareTo(a + b);
        }
    }
}