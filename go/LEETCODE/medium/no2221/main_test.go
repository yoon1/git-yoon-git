package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_triangularSum(t *testing.T) {
	tcs := []struct {
		input    []int
		expected int
	}{
		{[]int{1, 2, 3, 4, 5}, 8},
		{[]int{5}, 5},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := triangularSum(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
