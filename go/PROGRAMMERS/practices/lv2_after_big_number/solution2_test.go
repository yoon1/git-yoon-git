package main

import (
	"fmt"
	"testing"
	"time"
)

func Test_solution2(t *testing.T) {
	a := []int{}
	for i := 500000; i > 0; i-- {
		a = append(a, i)
	}
	tcs := []struct {
		Numbers []int
		Answer  []int
	}{
		//{[]int{2, 3, 3, 5}, []int{3, 5, 5, -1}},
		//{[]int{9, 1, 5, 3, 6, 2}, []int{-1, 5, 6, 6, -1, -1}},
		{a, []int{}},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			start := time.Now()
			solution_2(tc.Numbers)
			//assert.Equal(t, tc.Answer, res)
			fmt.Printf("실행시간: %s\n", time.Since(start))
		})
	}
}
