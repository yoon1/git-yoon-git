package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		a        []int
		b        []int
		expected []int
	}{
		{[]int{0, 1, 2, 3, 4}, []int{0, 1, 2, 2, 1}, []int{0, 4, 1, 3, 2}},
		{[]int{1, 2, 3, 4, 0}, []int{0, 1, 2, 3, 0}, []int{0, 1, 2, 3, 4}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := createTargetArray(tc.a, tc.b)
			assert.Equal(t, tc.expected, result)
		})
	}
}
