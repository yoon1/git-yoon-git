package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		root     []int
		expected int
	}{
		{[]int{1, 0, 1, 0, 1, 0, 1}, 22},
		{[]int{0}, 0},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := sumRootToLeaf(CreateTree(tc.root))
			assert.Equal(t, tc.expected, result)
		})
	}
}
