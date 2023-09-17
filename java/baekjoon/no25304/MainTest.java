package no25304;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class MainTest {
    @Test
    public void testScore() {
        int[] tcTotals = {260000};
        Item[][] tcItems = {
                {
                    new Item(20000, 5),
                    new Item(30000, 2),
                    new Item(10000, 6),
                    new Item(5000, 8),
                }
        };

        boolean[] expectedScores = {true};

        for (int i = 0; i < tcTotals.length; i++) {
            int total = tcTotals[i];
            Item[] items = tcItems[i];
            boolean expectedScore = expectedScores[i];
            assertEquals(expectedScore, Main.isValidBill(total, items));
        }
    }

}