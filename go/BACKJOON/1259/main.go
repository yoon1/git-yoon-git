package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func isPalindrome(s string) bool {
	length := len(s)
	for i := 0; i < length/2; i++ {
		if s[i] != s[length-i-1] {
			return false
		}
	}

	return true
}

func Solve(num int) string {
	if isPalindrome(strconv.Itoa(num)) {
		return "yes"
	}
	return "no"
}

func ScanInt() int64 {
	userVal, _ := r.ReadString('\n')
	input := strings.TrimSpace(userVal)
	n, _ := strconv.Atoi(input)
	return int64(n)
}

func main() {
	for {
		n := ScanInt()
		if n == 0 {
			return
		}
		fmt.Printf("%s\n", Solve(int(n)))
	}
}
