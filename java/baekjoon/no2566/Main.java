package no2566;

import java.util.Scanner;

class Max {
    int y, x, val;

    public Max(int y, int x, int val) {
        this.y = y;
        this.x = x;
        this.val = val;
    }

    public void update(int y, int x, int val) {
        this.y = y;
        this.x = x;
        this.val = val;
    }
}

public class Main {
    static final int SIZE = 9;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Max max = new Max(0, 0, -1);

        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {
                int v = scanner.nextInt();
                if (max.val < v) {
                    max.update(i, j, v);
                }
            }
        }
        scanner.close();

        System.out.println(max.val);
        System.out.printf("%d %d", max.y, max.x);
    }
}
