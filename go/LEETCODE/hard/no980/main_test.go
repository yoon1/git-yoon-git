package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		grid     [][]int
		expected int
	}{
		{[][]int{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}}, 2},
		//{[][]int{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}}, 4},
		//{[][]int{{0, 1}, {2, 0}}, 0},
	}

	for _, tc := range tcs {
		res := uniquePathsIII(tc.grid)
		assert.Equal(t, tc.expected, res)
	}
}
