package no25206;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Subject {
    double unit;
    String grade;

    public Subject(double unit, String grade) {
        this.unit = unit;
        this.grade = grade;
    }
}

public class Main {
    public static final Map<String, Double> subjectGradeMap = new HashMap<>() {{
        put("A+", 4.5);
        put("A0", 4.0);
        put("B+", 3.5);
        put("B0", 3.0);
        put("C+", 2.5);
        put("C0", 2.0);
        put("D+", 1.5);
        put("D0", 1.0);
        put("F", 0.0);
    }};

    public static double majorRating(Subject[] subjects) {
        double unitSum = 0;
        double subjectSum = 0;
        for (Subject subject : subjects) {
            if (subject.grade.equals("P")) {
                continue;
            }

            subjectSum += subject.unit * subjectGradeMap.get(subject.grade);
            unitSum += subject.unit;
        }

        if (unitSum == 0) {
            return 0;
        }

        return subjectSum / unitSum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Subject[] subjects = new Subject[20];
        String pattern = "(\\w+) (\\d+\\.\\d) (\\w+\\+*)";
        Pattern regex = Pattern.compile(pattern);

        for (int i = 0; i < 20; i++) {
            String input = scanner.nextLine();
            Matcher matcher = regex.matcher(input);
            if(matcher.find()) {
                double unit = Double.parseDouble(matcher.group(2));
                String grade = matcher.group(3);
                subjects[i] = new Subject(unit, grade);
            }
        }

        scanner.close();

        System.out.printf("%.6f", majorRating(subjects));
    }
}
