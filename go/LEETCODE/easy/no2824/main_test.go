package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    []int
		target   int
		expected int
	}{
		{[]int{-1, 1, 2, 3, 1}, 2, 3},
		{[]int{-6, 2, 5, -2, -7, -1, 3}, -2, 10},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := countPairs(tc.input, tc.target)
			assert.Equal(t, tc.expected, result)
		})
	}
}
