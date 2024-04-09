package main

import (
	"fmt"
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		s        []int
		key      int
		expected []int
	}{
		{[]int{5, 3, 6, 2, 4, NULL, 7}, 3, []int{5, 4, 6, 2, NULL, NULL, 7}},
		{[]int{5, 3, 6, 2, 4, NULL, 7}, 0, []int{5, 3, 6, 2, 4, NULL, 7}},
		{[]int{}, 0, []int{}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			//PrintTreeBFS(CreateTree(tc.expected))
			//fmt.Println()
			result := deleteNode(CreateTree(tc.s), tc.key)
			PrintTreeBFS(result)
			assert.Equal(t, IsSameTree(result, CreateTree(tc.expected)), true)
		})
	}
}

func Test_(t *testing.T) {
	// 변수 x에 값을 할당
	x := 10
	// 포인터 p에 x의 메모리 주소를 할당
	p := &x

	fmt.Println("Value of x:", x)  // 출력: Value of x: 10
	fmt.Println("Value of p:", *p) // 출력: Value of p: 10

	// 포인터를 통해 x의 값을 변경
	*p = 20

	fmt.Println("New value of x:", x) // 출력: New value of x: 20
}
