package main

func findMaxConsecutiveOnes(nums []int) int {
	maxCount := 0
	curCount := 0
	for _, num := range nums {
		if num == 1 {
			curCount++
		} else {
			if maxCount < curCount {
				maxCount = curCount
			}
			curCount = 0
		}
	}
	if maxCount < curCount {
		maxCount = curCount
	}

	return maxCount
}
