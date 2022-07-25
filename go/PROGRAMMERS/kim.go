package main

import (
	"fmt"
)

func solution(seoul []string) string {
	ch := make(chan int, 20)
	for idx, val := range seoul {
		go find(ch, idx, val)
	}

	for i := range ch {
		if i > 0 {
			return fmt.Sprintf("김서방은 %d에 있다", i)
		}
	}

	return ""
}

func find(ch chan<- int, idx int, val string) {
	const kim = "Kim"
	if val == kim {
		ch <- idx
	}

	ch <- 1
}

func main() {
	solution([]string{"Jane", "Kim"})
}
