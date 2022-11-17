package practices

import (
	"sync"
)

func solution(want []string, number []int, discount []string) int {
	res := 0

	m := make(map[string]int)
	for i, v := range want {
		m[v] = number[i]
	}

	var wg sync.WaitGroup
	length := len(discount) - 9
	passes := make(chan bool)
	for i := 0; i < length; i++ {
		wg.Add(1)
		go Cmp(&wg, m, discount[i:i+10], &passes)
	}

	go func() {
		wg.Wait()
		close(passes)
	}()

	for pass := range passes {
		if pass {
			res++
		}
	}

	return res
}

func Cmp(wg *sync.WaitGroup, target map[string]int, discount []string, ch *chan bool) {
	defer wg.Done()
	tm := make(map[string]int)
	for k, v := range target {
		tm[k] = v
	}

	for _, dc := range discount {
		if _, ok := tm[dc]; ok {
			tm[dc]--
			if tm[dc] <= 0 {
				delete(tm, dc)
			}
		}
		if len(tm) == 0 {
			*ch <- true
		}
	}
	*ch <- false
}
