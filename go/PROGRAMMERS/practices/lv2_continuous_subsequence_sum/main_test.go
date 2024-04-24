package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		sequence []int
		k        int
		expected []int
	}{
		//{[]int{1, 2, 3, 4, 5}, 7, []int{2, 3}},
		{[]int{1, 1, 1, 2, 3, 4, 5}, 5, []int{6, 6}},
		//{[]int{2, 2, 2, 2, 2}, 6, []int{0, 2}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := solution(tc.sequence, tc.k)
			assert.Equal(t, tc.expected, result)
		})
	}
}
