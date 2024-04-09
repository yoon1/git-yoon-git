package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    []int
		expected [][]int
	}{
		{[]int{1, 2, 3}, [][]int{
			{1, 2, 3},
			{1, 3, 2},
			{2, 1, 3},
			{2, 3, 1},
			{3, 1, 2},
			{3, 2, 1},
		}},
		{[]int{0, 1}, [][]int{{0, 1}, {1, 0}}},
		{[]int{1}, [][]int{{1}}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			res := permute(tc.input)
			//log.Println(res)
			assert.Equal(t, tc.expected, res)
		})
	}
}
