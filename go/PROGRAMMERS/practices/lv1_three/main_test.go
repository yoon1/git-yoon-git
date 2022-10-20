package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		Number []int
		Answer int
	}{
		{[]int{-2, 3, 0, 2, -5}, 2},
		{[]int{-3, -2, -1, 0, 1, 2, 3}, 5},
		{[]int{-1, 1, -1, 1}, 0},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.Number)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
