package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		Lines  [][]int
		Answer int
	}{
		{[][]int{{0, 1}, {2, 5}, {3, 9}}, 2},
		{[][]int{{-1, 1}, {1, 3}, {3, 9}}, 0},
		{[][]int{{0, 5}, {3, 9}, {1, 10}}, 8},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.Lines)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
