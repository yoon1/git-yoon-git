package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    *ListNode
		expected *ListNode
	}{
		{
			MakeListNode([]int{5, 2, 13, 3, 8}),
			MakeListNode([]int{13, 8}),
		},
		{
			MakeListNode([]int{10, 2, 4, 3}),
			MakeListNode([]int{10, 4, 3}),
		},
		{
			MakeListNode([]int{1, 1, 1, 1}),
			MakeListNode([]int{1, 1, 1, 1}),
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := removeNodes(tc.input)
			assert.True(t, CompareListNode(result, tc.expected))
		})
	}
}
