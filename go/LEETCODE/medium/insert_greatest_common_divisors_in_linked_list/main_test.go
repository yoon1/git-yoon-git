package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_insertGreatestCommonDivisors(t *testing.T) {
	tcs := []struct {
		root   *ListNode
		aspect []int
	}{
		// case 1
		{
			root:   MakeListNode([]int{18, 6, 10, 3}),
			aspect: []int{18, 6, 6, 2, 10, 1, 3},
		},
		// case 2
		{
			root:   MakeListNode([]int{7}),
			aspect: []int{7},
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := insertGreatestCommonDivisors(tc.root)
			assert.Equal(t, tc.aspect, result.Traverse())
		})
	}
}
