package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		Score  [][]int
		Answer []int
	}{
		{[][]int{{80, 70}, {90, 50}, {40, 70}, {50, 80}}, []int{1, 2, 4, 3}},
		{[][]int{{80, 70}, {70, 80}, {30, 50}, {90, 100}, {100, 90}, {100, 100}, {10, 30}}, []int{4, 4, 6, 2, 2, 1, 7}},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.Score)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
