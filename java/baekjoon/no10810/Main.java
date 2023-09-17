package no10810;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

class Shoot {
    int startBucketIndex;
    int endBucketIndex;
    int ballNum;

    public Shoot(int startBucketIndex, int endBucketIndex, int ballNum) {
        this.startBucketIndex = startBucketIndex;
        this.endBucketIndex = endBucketIndex;
        this.ballNum = ballNum;
    }
}

public class Main {
    static int[] game(int N, Shoot[] shoots) {
        int[] buckets = new int[N];

        Arrays.stream(shoots)
                .forEach(shoot -> IntStream.range(shoot.startBucketIndex, shoot.endBucketIndex+1)
                        .forEach(bucketIndex -> buckets[bucketIndex-1] = shoot.ballNum));

        return buckets;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        Shoot[] shoots = new Shoot[M];
        for (int n = 0; n < M; n++) {
            int i = scanner.nextInt();
            int j = scanner.nextInt();
            int k = scanner.nextInt();
            shoots[n] = new Shoot(i, j, k);
        }

        int[] buckets = game(N, shoots);
        Arrays.stream(buckets).forEach(bucket -> System.out.printf("%d ", bucket));
        scanner.close();
    }
}
