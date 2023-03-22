package main

import (
	"runtime"
	"sync"
)

func solution_1(numbers []int) []int {
	runtime.GOMAXPROCS(runtime.NumCPU())

	length := len(numbers)
	t := make([]int, length)
	wg := sync.WaitGroup{}
	for i, number := range numbers {
		wg.Add(1)
		go func(ci, cnum int) {
			defer wg.Done()
			near_1(&t[ci], cnum, ci, &numbers, length)
		}(i, number)
	}
	wg.Wait()

	return t
}

func near_1(t *int, cur, curIdx int, numbers *[]int, length int) {
	var v = -1
	for i := curIdx; i < length; i++ {
		if cur < (*numbers)[i] {
			v = (*numbers)[i]
			break
		}
	}

	*t = v
}
