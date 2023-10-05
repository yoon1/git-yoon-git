package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_merge(t *testing.T) {
	tcs := []struct {
		nums1    []int
		m        int
		nums2    []int
		n        int
		expected []int
	}{
		{[]int{1, 2, 3, 0, 0, 0}, 3, []int{2, 5, 6}, 3, []int{1, 2, 2, 3, 5, 6}},
		{[]int{1}, 1, []int{}, 0, []int{1}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			merge(tc.nums1, tc.m, tc.nums2, tc.n)
			assert.Equal(t, tc.expected, tc.nums1)
		})
	}
}
