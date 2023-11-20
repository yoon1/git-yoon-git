package main

import "sort"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minPairSum(nums []int) int {
	sort.Ints(nums)
	var (
		i, j = 0, len(nums) - 1
		res  = 0
	)

	for i < j {
		res = max(res, nums[i]+nums[j])
		i++
		j--
	}

	return res
}
