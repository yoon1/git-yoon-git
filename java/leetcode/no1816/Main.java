package no1816;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public String truncateSentence(String s, int k) {
        String[] parts = s.split(" ");
        String[] selectedParts = Arrays.copyOfRange(parts, 0, k);

        return String.join(" ", selectedParts);
    }
}


class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.truncateSentence("What is the solution to this problem", 4));
    }
}