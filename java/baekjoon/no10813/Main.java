package no10813;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

class Shuffle {
    int i, j;

    public Shuffle(int i, int j) {
        this.i = i;
        this.j = j;
    }
}

public class Main {
    private static int[] changeBalls(int n, Shuffle[] shuffles) {
        int[] buckets = IntStream.rangeClosed(1, n).toArray();
        Arrays.stream(shuffles)
                .forEach(shuffle -> {
                    int t = buckets[shuffle.i];
                    buckets[shuffle.i] = buckets[shuffle.j];
                    buckets[shuffle.j] = t;
                });

        return buckets;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        Shuffle[] shuffles = new Shuffle[M];
        for (int n = 0; n < M; n++) {
            int i = scanner.nextInt();
            int j = scanner.nextInt();
            shuffles[n] = new Shuffle(--i, --j);
        }

        int[] buckets = changeBalls(N, shuffles);
        Arrays.stream(buckets).forEach(bucket -> System.out.printf("%d ", bucket));
        scanner.close();
    }
}
