package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    *ListNode
		expected *ListNode
	}{
		{
			MakeListNode([]int{1, 3, 4, 7, 1, 2, 6}),
			MakeListNode([]int{1, 3, 4, 1, 2, 6}),
		},
		{
			MakeListNode([]int{1, 2, 3, 4}),
			MakeListNode([]int{1, 2, 4}),
		},
		{
			MakeListNode([]int{2, 1}),
			MakeListNode([]int{2}),
		},
		{
			MakeListNode([]int{10}),
			MakeListNode([]int{10}),
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := deleteMiddle(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
