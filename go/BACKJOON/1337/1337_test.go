package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve9177(t *testing.T) {
	tcs := []struct {
		Nums   []int64
		Answer int64
	}{
		{[]int64{5, 6, 7}, 2},
		{[]int64{5, 7, 9, 8492, 8493, 192398}, 2},
		{[]int64{1000, 2000, 3000, 4000}, 4},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.Nums)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
