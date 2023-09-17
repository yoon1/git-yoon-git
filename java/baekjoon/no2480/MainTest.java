package no2480;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class MainTest {
    @Test
    public void testScore() {
        int[][] testCases = {
                {3,3,6},
                {3,6,3},
                {6,3,3},
                {2, 2, 2},
                {6, 2, 5},
                {2, 1, 3},
        };

        int[] expectedScores = {1300, 1300, 1300, 12000, 600, 300};

        for (int i = 0; i < testCases.length; i++) {
            int[] points = testCases[i];
            int expectedScore = expectedScores[i];
            assertEquals(expectedScore, Main.score(points));
        }
    }

}