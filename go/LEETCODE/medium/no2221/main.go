package main

func triangularSum(nums []int) int {
	for len(nums) > 1 {
		nums = TwoSumAndMod10(nums)
	}

	return nums[0]
}

func TwoSumAndMod10(nums []int) []int {
	length := len(nums)
	res := make([]int, length-1)
	for i := 0; i < length-1; i++ {
		res[i] = (nums[i] + nums[i+1]) % 10
	}
	return res
}
