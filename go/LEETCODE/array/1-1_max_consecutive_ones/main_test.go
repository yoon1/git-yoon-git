package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindMaxConsecutiveOnes(t *testing.T) {
	tcs := []struct {
		input  []int
		output int
	}{
		{[]int{1, 1, 0, 1, 1, 1}, 3},
		{[]int{1, 0, 1, 1, 0, 1}, 2},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findMaxConsecutiveOnes(tc.input)
			assert.Equal(t, result, tc.output)
		})
	}
}
