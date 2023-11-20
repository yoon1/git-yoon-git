package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    []int
		expected int
	}{
		{[]int{1, 13, 10, 12, 31}, 6},
		{[]int{2, 2, 2}, 1},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := countDistinctIntegers(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
