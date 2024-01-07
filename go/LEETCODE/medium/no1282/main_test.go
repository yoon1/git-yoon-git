package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_triangularSum(t *testing.T) {
	tcs := []struct {
		groupSizes []int
		expected   [][]int
	}{
		//{
		//	[]int{3, 3, 3, 3, 3, 1, 3},
		//	[][]int{{5}, {0, 1, 2}, {3, 4, 6}},
		//},
		{
			[]int{2, 1, 3, 3, 3, 2},
			[][]int{{1}, {0, 5}, {2, 3, 4}},
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := groupThePeople(tc.groupSizes)
			assert.Equal(t, tc.expected, result)
		})
	}
}
