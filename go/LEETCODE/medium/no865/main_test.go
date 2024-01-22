package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_triangularSum(t *testing.T) {
	tcs := []struct {
		board    []int
		expected []int
	}{
		{[]int{3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4}, []int{2, 7, 4}},
		//{[]int{1}, []int{1}},
		//{[]int{0, 1, 3, NULL, 2}, []int{2}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := subtreeWithAllDeepest(CreateTree(tc.board))
			expectedTree := CreateTree(tc.expected)
			assert.Equal(t, IsSameTree(result, expectedTree), true)
		})
	}
}
