package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_plusOne(t *testing.T) {
	tcs := []struct {
		input    []int
		expected []int
	}{
		//{[]int{1, 2, 3}, []int{1, 2, 4}},
		//{[]int{4, 3, 2, 1}, []int{4, 3, 2, 2}},
		{[]int{9}, []int{1, 0}},
		{[]int{9, 9}, []int{1, 0, 0}},
		{[]int{1, 9, 9}, []int{2, 0, 0}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := plusOne(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
