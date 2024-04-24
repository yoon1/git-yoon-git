package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		root     []int
		expected []int
	}{}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			bstToGst(CreateTree(tc.root))
		})
	}
}
