package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    *ListNode
		k        int
		expected *ListNode
	}{
		{
			MakeListNode([]int{1, 2, 3, 4, 5}),
			2,
			MakeListNode([]int{1, 4, 3, 2, 5}),
		},
		{
			MakeListNode([]int{7, 9, 6, 6, 7, 8, 3, 0, 9, 5}),
			5,
			MakeListNode([]int{7, 9, 6, 6, 8, 7, 3, 0, 9, 5}),
		},
		{
			MakeListNode([]int{1}),
			1,
			MakeListNode([]int{1}),
		},
		{
			MakeListNode([]int{1, 2}),
			1,
			MakeListNode([]int{2, 1}),
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := swapNodes(tc.input, tc.k)
			PrintNode(tc.expected)
			PrintNode(result)
			assert.True(t, CompareListNode(result, tc.expected))
		})
	}
}
