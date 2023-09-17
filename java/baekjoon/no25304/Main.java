package no25304;

import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Item {
    int price;
    int number;

    public Item(int price, int number) {
        this.price = price;
        this.number = number;
    }
}

public class Main {
    static boolean isValidBill(int total, Item items[]) {
        int sum = Stream.of(items)
                .mapToInt(item -> item.price * item.number)
                .sum();
        return sum == total;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int total = scanner.nextInt();
        int itemNumber = scanner.nextInt();
        Item[] items = new Item[itemNumber];

        for (int i = 0; i < itemNumber; i++) {
            int price = scanner.nextInt();
            int number = scanner.nextInt();
            items[i] = new Item(price, number);
        }

        System.out.println(isValidBill(total, items) ? "Yes" : "No");

        scanner.close();
    }
}
