package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve9177(t *testing.T) {
	tcs := []struct {
		Nums   []int64
		Answer int
	}{
		//{[]int64{5, 6, 7}, 2},
		//{[]int64{5, 7, 9, 8492, 8493, 192398}, 2},
		//{[]int64{1000, 2000, 3000, 4000}, 4},
		//{[]int64{5, 6, 7, 8}, 1},
		//{[]int64{5, 6, 7, 8, 14, 15, 16, 17, 18}, 0},
		//{[]int64{5, 6, 7, 14, 15, 16, 17, 20}, 1},
		//{[]int64{1, 5}, 3},
		{[]int64{1}, 4},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.Nums)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
