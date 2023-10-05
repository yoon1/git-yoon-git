package no1816;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public String reverseWords(String s) {
        String[] parts = s.split(" ");

        int len = parts.length;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < len; i++) {
            StringBuilder sb = new StringBuilder(parts[i]);
            String reversed = sb.reverse().toString();
            res.append(reversed);
            if (i != len - 1) {
                res.append(" ");
            }
        }

        return res.toString();
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.reverseWords("Let's take LeetCode contest"));
    }
}