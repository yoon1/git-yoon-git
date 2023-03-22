package main

import (
	"sync"
)

func solution_2(numbers []int) []int {
	length := len(numbers)
	t := make([]int, length)
	wg := sync.WaitGroup{}
	for i := range numbers {
		wg.Add(1)
		go func(ci int) {
			defer wg.Done()
			near_2(&t[ci], ci, numbers, length)
		}(i)
	}
	wg.Wait()

	return t
}

func near_2(t *int, ci int, nums []int, length int) {
	*t = -1

	for i := ci; i < length; i++ {
		if nums[ci] < nums[i] {
			*t = nums[i]
			return
		}
	}
}
