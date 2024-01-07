package main

func countPairs(nums []int, target int) int {
	length := len(nums)
	res := 0
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			if nums[i]+nums[j] < target {
				res++
			}
		}
	}

	return res
}
