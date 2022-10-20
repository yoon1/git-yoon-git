package main

import (
	"bytes"
	"strconv"
)

// Source: https://school.programmers.co.kr/learn/courses/30/lessons/131128
// string +=  --> bytes.Buffer

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func countNum(s string) [10]int {
	res := [10]int{}
	for _, v := range s {
		res[v-'0']++
	}
	return res
}
func solution(X string, Y string) (res string) {
	xNum := countNum(X)
	yNum := countNum(Y)

	buf := new(bytes.Buffer)
	for i := 9; i >= 1; i-- {
		cnt := min(xNum[i], yNum[i])
		for j := 0; j < cnt; j++ {
			buf.WriteString(strconv.Itoa(i))
		}
	}

	res = buf.String()

	cnt := min(xNum[0], yNum[0])
	if res == "" {
		if cnt > 0 {
			return "0"
		} else {
			return "-1"
		}
	}

	for j := 0; j < cnt; j++ {
		buf.WriteString(strconv.Itoa(0))
	}

	res = buf.String()

	return
}
