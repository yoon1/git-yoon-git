package main

import (
	"github.com/stretchr/testify/assert"
	"log"
	"sort"
	"testing"
)

func Test_removeElement(t *testing.T) {
	tcs := []struct {
		nums    []int
		val     int
		resNums []int
		k       int
	}{
		{[]int{}, 0, []int{}, 0},
		{[]int{1}, 1, []int{}, 0},
		{[]int{3, 2, 2, 3}, 3, []int{2, 2}, 2},
		{[]int{0, 1, 2, 2, 3, 0, 4, 2}, 2, []int{0, 0, 1, 3, 4}, 5},
		{[]int{2, 2, 2, 3, 2, 2, 3}, 3, []int{2, 2, 2, 2, 2}, 5},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			k := removeElement(tc.nums, tc.val)
			assert.Equal(t, tc.k, k)
			if k == 0 {
				return
			}

			log.Println(tc.nums)
			sort.Slice(tc.nums[:k], func(i, j int) bool {
				return tc.nums[i] < tc.nums[j]
			})

			for i := 0; i < k; i++ {
				assert.Equal(t, tc.nums[i], tc.resNums[i])
			}
		})
	}
}
