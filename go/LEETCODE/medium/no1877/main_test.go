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
		{[]int{3, 5, 2, 3}, 7},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := minPairSum(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
