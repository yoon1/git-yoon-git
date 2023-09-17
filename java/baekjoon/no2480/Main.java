package no2480;

import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static boolean equal(int a, int b) {
        return a == b;
    }

    static boolean equal(int a, int b, int c) {
        return a == b && b == c;
    }

    static int score(int points[]) {
        if (equal(points[0], points[1], points[2]))  {
            return 10000 + (points[0] * 1000);
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < 3; j++) {
                if (i == j ) {
                    continue;
                }
                if (equal(points[i], points[j])) {
                    return 1000 + (points[i] * 100);
                }
            }
        }

        return  IntStream.of(points).max().getAsInt()* 100;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] points = new int[3];

        for (int i = 0; i < 3; i++) {
            points[i] = scanner.nextInt();
        }

        System.out.println(score(points));
    }
}
