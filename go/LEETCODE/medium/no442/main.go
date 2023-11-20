package main

import "sort"

func findDuplicates(nums []int) []int {
	sort.Ints(nums)
	var (
		pre = nums[0]
		res = []int{}
	)

	for i := 1; i < len(nums); i++ {
		if pre == nums[i] && (len(res) == 0 || nums[i] != res[len(res)-1]) {
			res = append(res, nums[i])
		}
		pre = nums[i]
	}

	return res
}
