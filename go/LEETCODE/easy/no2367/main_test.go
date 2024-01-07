package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    []int
		diff     int
		expected int
	}{
		{[]int{0, 1, 4, 6, 7, 10}, 3, 2},
		{[]int{4, 5, 6, 7, 8, 9}, 2, 2},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := arithmeticTriplets(tc.input, tc.diff)
			assert.Equal(t, tc.expected, result)
		})
	}
}
