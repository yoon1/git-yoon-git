package no1773;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int count = 0;
        for (List<String> item:items) {
            int idx = -1;
            switch (ruleKey) {
                case "type":
                    idx = 0;
                    break;
                case "color":
                    idx = 1;
                    break;
                case "name":
                    idx = 2;
                    break;
            }

            if (item.get(idx).equals(ruleValue)) {
                count++;
            }
        }
        return count;
    }


}


class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        List<List<String>> items = new ArrayList<>();
        List<String> item1 = new ArrayList<>();
        item1.add("phone");
        item1.add("blue");
        item1.add("pixel");
        items.add(item1);

        List<String> item2 = new ArrayList<>();
        item2.add("computer");
        item2.add("silver");
        item2.add("lenovo");
        items.add(item2);

        List<String> item3 = new ArrayList<>();
        item3.add("phone");
        item3.add("gold");
        item3.add("iphone");
        items.add(item3);


        System.out.println(solution.countMatches(items, "color", "silver"));
    }
}