package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		nums     []int
		expected int
	}{
		{[]int{1, 2, 3, 2}, 4},
		{[]int{1, 1, 1, 1, 1}, 0},
		{[]int{1, 2, 3, 4, 5}, 15},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := sumOfUnique(tc.nums)
			assert.Equal(t, tc.expected, result)
		})
	}
}
