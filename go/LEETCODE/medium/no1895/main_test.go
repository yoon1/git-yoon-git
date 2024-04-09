package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		grid     [][]int
		expected int
	}{
		{[][]int{{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}}, 3},
		{[][]int{{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}}, 2},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := largestMagicSquare(tc.grid)
			assert.Equal(t, tc.expected, result)
		})
	}
}
