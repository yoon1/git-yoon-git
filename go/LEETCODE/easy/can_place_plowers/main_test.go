package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		flowerbed []int
		n         int
		expected  bool
	}{
		{[]int{1, 0, 0, 0, 1}, 1, true},
		{[]int{1, 0, 0, 0, 1}, 2, false},
		{[]int{0, 0}, 1, true},
		{[]int{0, 1}, 1, false},
		{[]int{0, 1}, 0, true},
		{[]int{0}, 1, true},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := canPlaceFlowers(tc.flowerbed, tc.n)
			assert.Equal(t, tc.expected, result)
		})
	}
}
