package main

import "fmt"

func pivotInteger(n int) int {
	var l, r, p = 1, n, (n / 2) + 1
	var visited = make([]bool, n+1)
	for p <= r && !visited[p] {
		visited[p] = true
		fmt.Println(p)
		var ls, rs = sum(l, p), sum(p, r)
		switch {
		case ls == rs:
			return p
		case ls > rs:
			p = (l + p) / 2
		case ls < rs:
			p = (r + p) / 2
		}
	}

	return -1
}

func sum(start, end int) int {
	var res = 0
	for i := start; i <= end; i++ {
		res += i
	}
	return res
}
