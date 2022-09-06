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
		{[]int{12, 345, 2, 6, 7896}, 2},
		{[]int{555, 901, 482, 1771}, 1},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findNumbers(tc.input)
			assert.Equal(t, result, tc.output)
		})
	}
}
