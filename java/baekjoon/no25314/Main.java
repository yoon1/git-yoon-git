package no25314;

import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Stream;

public class Main {
    static String dataTypeName(int n) {
        Function<String, String> s = str -> {
            StringBuilder sb = new StringBuilder();
            sb.append(str.repeat(Math.max(0, n/4)));

            return sb.toString();
        };

        return s.apply("long ") + "int";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(dataTypeName(N));

        scanner.close();
    }
}
