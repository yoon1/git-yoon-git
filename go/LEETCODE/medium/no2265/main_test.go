package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		elements []int
		expected int
	}{
		{[]int{4, 8, 5, 0, 1, NULL, 6}, 5},
		{[]int{1}, 1},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			root := CreateTree(tc.elements)
			result := averageOfSubtree(root)
			assert.Equal(t, tc.expected, result)
		})
	}
}
