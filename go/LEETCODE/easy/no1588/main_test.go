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
		{[]int{1, 4, 2, 5, 3}, 58},
		//{[]int{1, 2}, 3},
		//{[]int{10, 11, 12}, 66},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := sumOddLengthSubarrays(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
