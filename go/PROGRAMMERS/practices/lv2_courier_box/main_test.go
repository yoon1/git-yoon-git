package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Main(t *testing.T) {
	tcs := []struct {
		Order  []int
		Answer int
	}{
		{[]int{4, 3, 1, 2, 5}, 2},
		{[]int{5, 4, 3, 2, 1}, 5},
		{[]int{2, 1, 4, 3}, 4},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.Order)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
