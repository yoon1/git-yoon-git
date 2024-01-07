package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		nums     []int
		expected []int
	}{
		{[]int{5, 4, 2, 3}, []int{3, 2, 5, 4}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := numberGame(tc.nums)
			assert.Equal(t, tc.expected, result)
		})
	}
}
