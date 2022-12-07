package main

import (
	"fmt"
)

func Solve(N, M int) string {
	if N <= M {
		return "No"
	}
	return "Yes"
}

func main() {
	var N, M int
	for {
		fmt.Scanf("%d %d", &N, &M)
		if N == 0 && M == 0 {
			return
		}
		fmt.Printf("%s\n", Solve(N, M))
	}
}
