package main

import "log"

func bubbleSort(nums []int) {
	for hasSwap := true; hasSwap; {
		hasSwap = false
		for i := 0; i < len(nums)-1; i++ {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
				hasSwap = true
			}
		}
	}
}

func main() {
	arr := []int{4, 2, 3, 4, 1}
	bubbleSort(arr)
	log.Println(arr)
}
