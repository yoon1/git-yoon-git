package main

import "fmt"

func findNumbers(nums []int) int {
	count := 0
	for _, num := range nums {
		if len(fmt.Sprintf("%d", num))%2 == 0 {
			count++
		}
	}

	return count
}
