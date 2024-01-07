package main

import "fmt"

func arithmeticTriplets(nums []int, diff int) int {
	var (
		res    int
		length = len(nums)
	)

	for i := 0; i < length; i++ {
		for j := i; j < length; j++ {
			if nums[j]-nums[i] == diff {
				fmt.Println(nums[j], nums[i])
				res++

			}
		}
	}

	return res
}
