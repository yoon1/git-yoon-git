package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		size     []int
		expected [][]int
	}{
		{[]int{3, 3, 3, 3, 3, 1, 3}, [][]int{{5}, {0, 1, 2}, {3, 4, 6}}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := groupThePeople(tc.size)
			assert.Equal(t, tc.expected, result)
		})
	}
}
