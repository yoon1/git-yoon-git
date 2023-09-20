package no1071;

class Solution {
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static boolean isMultipleUnit(String target, int unitLength, String unit) {
        int start = 0;
        int end = unitLength;
        while(end <= target.length()) {
            if (!target.substring(start, end).equals(unit)) {
                return false;
            }
            start += unitLength;
            end += unitLength;
        }

        return true;
    }

    public String gcdOfStrings(String str1, String str2) {
        int unitLength = gcd(str1.length(), str2.length());
        String unit = str1.substring(0, unitLength);
        if (isMultipleUnit(str1, unitLength, unit) && isMultipleUnit(str2, unitLength, unit)) {
            return unit;
        }

        return "";
    }
}


class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.gcdOfStrings("ABCABC", "ABC"));
        System.out.println(solution.gcdOfStrings("ABABAB", "ABAB"));
        System.out.println(solution.gcdOfStrings("LEET", "CODE"));
    }
}