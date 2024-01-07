package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input1   []int
		input2   []int
		expected []int
	}{
		{[]int{2, 1, 4}, []int{1, 0, 3}, []int{0, 1, 1, 2, 3, 4}},
		//{[]int{1, NULL, 8}, []int{8, 1}, []int{1, 1, 8, 8}},
	}

	// A xor (A xor
	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			root1 := CreateTree(tc.input1)
			root2 := CreateTree(tc.input2)
			result := getAllElements(root1, root2)
			//arr := []int{}
			//preorder(root1, &arr)
			//fmt.Println(arr)
			assert.Equal(t, tc.expected, result)
		})
	}
}
