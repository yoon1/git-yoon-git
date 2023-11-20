package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_leafSimilar(t *testing.T) {
	tcs := []struct {
		input    []int
		expected []int
	}{
		{[]int{5, 10, -5}, []int{5, 10}},
		{[]int{8, -8}, []int{}},
		{[]int{10, 2, -5}, []int{10}},
		{[]int{-2, -1, 1, 2}, []int{-2, -1, 1, 2}},
		{[]int{-2, -2, -2, 1}, []int{-2, -2, -2, 1}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := asteroidCollision(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
