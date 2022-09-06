package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortedSquares(t *testing.T) {
	tcs := []struct {
		input  []int
		output []int
	}{
		{[]int{-4, -1, 0, 3, 10}, []int{0, 1, 9, 16, 100}},
		{[]int{-7, -3, 2, 3, 11}, []int{4, 9, 9, 49, 121}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := sortedSquares(tc.input)
			assert.Equal(t, tc.output, result)
		})
	}
}
