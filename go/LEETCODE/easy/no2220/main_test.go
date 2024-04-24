package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		start    int
		goal     int
		expected int
	}{
		{10, 7, 3},
		{3, 4, 3},
		{10, 82, 3}, // 1010010, 1010
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := minBitFlips(tc.start, tc.goal)
			assert.Equal(t, tc.expected, result)
		})
	}
}
