package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

const maxLen = 201

var dp [maxLen][maxLen]int
var tdp [maxLen][maxLen]int
var one, two, three string
var one_len, two_len, three_len int
var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func init() {
	for n := 0; n < maxLen; n++ {
		for m := 0; m < maxLen; m++ {
			tdp[n][m] = -1
		}
	}
}

func Init() {
	dp = tdp
}

func Search(one_idx, two_idx, count int) int {
	if one_idx+two_idx == three_len {
		if count == three_len {
			return 1
		} else {
			return 0
		}
	}

	if dp[one_idx][two_idx] != -1 {
		return dp[one_idx][two_idx]
	}

	if one_idx < one_len && three[one_idx+two_idx] == one[one_idx] && Search(one_idx+1, two_idx, count+1) > 0 {
		dp[one_idx][two_idx] = 1
		return 1
	}

	if two_idx < two_len && three[one_idx+two_idx] == two[two_idx] && Search(one_idx, two_idx+1, count+1) > 0 {
		dp[one_idx][two_idx] = 1
		return 1
	}

	dp[one_idx][two_idx] = 0
	return dp[one_idx][two_idx]
}

func Solve(one_, two_, three_ string) bool {
	Init()
	one, two, three = one_, two_, three_
	one_len, two_len, three_len = len(one), len(two), len(three)
	if Search(0, 0, 0) > 0 {
		return true
	}
	return false
}

func ScanInt() int {
	userVal, _ := r.ReadString('\n')
	input := strings.TrimSpace(userVal)
	n, _ := strconv.Atoi(input)
	return n
}

func ScanString() string {
	str, _ := r.ReadString('\n') // 여기서 text는 마지막에 줄바꿈 문자를 포함하므로
	str = strings.TrimSpace(str) // 줄바꿈 문자를 제거해야 함
	return str
}

func ScanWords() {
	str := ScanString()
	ss := strings.Split(str, " ")
	one, two, three = ss[0], ss[1], ss[2]
}

func main() {
	n := ScanInt()
	for i := 1; i <= n; i++ {
		ScanWords()
		res := Solve(one, two, three)
		var yn string
		if res {
			yn = "yes"
		} else {
			yn = "no"
		}
		w.WriteString("Data set " + strconv.Itoa(i) + ": " + yn + "\n")
		w.Flush()
	}
}
