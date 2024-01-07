package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		customFunction func(int, int) int
		z              int
		expected       [][]int
	}{
		{
			customFunction: func(x int, y int) int { return x + y },
			z:              5,
			expected:       [][]int{{1, 4}, {2, 3}, {3, 2}, {4, 1}},
		},
		{
			customFunction: func(x int, y int) int { return x * y },
			z:              5,
			expected:       [][]int{{1, 5}, {5, 1}},
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findSolution(tc.customFunction, tc.z)
			assert.Equal(t, tc.expected, result)
		})
	}
}
