package main

import "sort"

func numberGame(nums []int) []int {
	// 5 4 2 3
	sort.Ints(nums)
	for i := 0; i < len(nums); i += 2 {
		nums[i], nums[i+1] = nums[i+1], nums[i]
	}
	return nums
}
