package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		arr      []int
		expected []int
	}{
		{[]int{2, 0, 2, 1, 1, 0}, []int{0, 0, 1, 1, 2, 2}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			sortColors(tc.arr)
			assert.Equal(t, tc.arr, tc.expected)
		})
	}
}
