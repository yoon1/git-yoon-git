package main

import "math"

func leftRightDifference(nums []int) []int {
	var length = len(nums)
	var left = make([]int, length)
	var right = make([]int, length)

	// move
	for i := 1; i < length; i++ {
		left[i] = left[i-1] + nums[i-1]
		right[length-1-i] = right[length-i] + nums[length-i]
	}

	// sum
	for i := 0; i < length; i++ {
		nums[i] = int(math.Abs(float64(left[i] - right[i])))
	}

	return nums
}
