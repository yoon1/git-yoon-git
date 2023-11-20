package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    []int
		expected []int
	}{
		{[]int{4, 3, 2, 7, 8, 2, 3, 1}, []int{2, 3}},
		{[]int{1, 1, 2}, []int{1}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findDuplicates(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
