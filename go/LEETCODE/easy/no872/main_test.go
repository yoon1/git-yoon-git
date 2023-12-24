package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_leafSimilar(t *testing.T) {
	tcs := []struct {
		a        []int
		b        []int
		expected bool
	}{
		{[]int{3, 5, 1, 6, 2, 9, 8, NULL, NULL, 7, 4}, []int{3, 5, 1, 6, 7, 4, 2, NULL, NULL, NULL, NULL, NULL, NULL, 9, 8}, true},
		{[]int{1, 2, 3}, []int{1, 3, 2}, false},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			root1 := CreateTree(tc.a)
			root2 := CreateTree(tc.b)
			result := leafSimilar(root1, root2)
			assert.Equal(t, tc.expected, result)
		})
	}
}
