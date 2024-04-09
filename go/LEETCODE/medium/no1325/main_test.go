package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input1   []int
		target   int
		expected []int
	}{
		{[]int{1, 2, 3, 2, NULL, 2, 4}, 2, []int{1, NULL, 3, NULL, 4}},
		//{[]int{1, NULL, 8}, []int{8, 1}, []int{1, 1, 8, 8}},
	}

	// A xor (A xor
	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			root1 := CreateTree(tc.input1)
			result := removeLeafNodes(root1, tc.target)
			assert.Equal(t, tc.expected, result)
		})
	}
}
