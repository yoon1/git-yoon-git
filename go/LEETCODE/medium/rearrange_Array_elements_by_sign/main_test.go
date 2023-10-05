package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    []int
		expected []int
	}{
		{[]int{3, 1, -2, -5, 2, -4}, []int{3, -2, 1, -5, 2, -4}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := rearrangeArray(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
