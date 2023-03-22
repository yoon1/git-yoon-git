package main

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
	"time"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		Numbers []int
		Answer  []int
	}{
		{[]int{2, 3, 3, 5}, []int{3, 5, 5, -1}},
		{[]int{9, 1, 5, 3, 6, 2}, []int{-1, 5, 6, 6, -1, -1}},
		{[]int{5, 4, 3, 2, 1, 2}, []int{-1, -1, -1, -1, 2, -1}},
		{[]int{1, 2, 3, 4}, []int{2, 3, 4, -1}},
		{[]int{1, 2, 3, 2, 1}, []int{2, 3, -1, -1, -1}},
		{[]int{1, 2, 1, 2, 1}, []int{2, -1, 2, -1, -1}},
		{[]int{8, 8, 8, 1, 2, 9, 1, 1}, []int{9, 9, 9, 2, 9, -1, -1, -1}},
		{[]int{1, 7, 7, 2, 9, 10}, []int{7, 9, 9, 9, 10, -1}},
	}

	for _, tc := range tcs {
		t.Run("ok_", func(t *testing.T) {
			start := time.Now()
			res := solution(tc.Numbers)
			assert.Equal(t, tc.Answer, res)
			fmt.Printf("실행시간: %s\n", time.Since(start))
		})
	}
}
