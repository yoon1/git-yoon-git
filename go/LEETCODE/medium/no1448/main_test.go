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
		{[]int{3, 1, 4, 3, NULL, 1, 5}, 4},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := goodNodes(CreateTree(tc.root))
			assert.Equal(t, tc.expected, result)
		})
	}
}
