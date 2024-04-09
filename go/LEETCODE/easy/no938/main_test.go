package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		root     []int
		low      int
		high     int
		expected int
	}{
		{[]int{10, 5, 15, 3, 7, NULL, 18}, 7, 15, 32},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := rangeSumBST(CreateTree(tc.root), tc.low, tc.high)
			assert.Equal(t, tc.expected, result)
		})
	}
}
