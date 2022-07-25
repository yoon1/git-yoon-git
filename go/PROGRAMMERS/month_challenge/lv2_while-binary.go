package main

import (
	"fmt"
)

func solution(s string) []int {
	round := 0
	zero := 0
	curZero := 0
	for s != "1" {
		fmt.Printf("t1: %T\n", s)
		curZero, s = rounds(s)
		zero += curZero
		round++
	}
	return []int{zero, round}
}

func rounds(s string) (int, string) {
	allCnt := len(s)
	zeroCnt := countZero(s)
	binary := toBinary(allCnt - zeroCnt) // allCnt - zerCnt : oneCnt
	fmt.Println(binary)
	return zeroCnt, binary
}

func countZero(num string) int {
	zeroCnt := 0
	for _, v := range num {
		if string(v) == "0" {
			zeroCnt++
		}
	}
	return zeroCnt
}

func toBinary(n int) string {
	r := ""
	for n != 0 {
		switch n % 2 {
		case 0:
			r += "0"
		case 1:
			r += "1"
		}
		n /= 2
	}
	return r
}
