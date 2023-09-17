package no25314;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.shadow.com.univocity.parsers.common.TextParsingException;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class MainTest {
    @Test
    public void testScore() {
        int[] tcs = {4, 20};
        String[] expected = {"long int", "long long long long long int"};

        for (int i = 0; i < tcs.length; i++) {
            int tc = tcs[i];
            String ex = expected[i];
            assertEquals(ex, Main.dataTypeName(tc));
        }
    }

}