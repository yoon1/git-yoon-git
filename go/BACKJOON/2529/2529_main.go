package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)

	s   []string
	min []string
	max []string
)

func Init(n int, data []string) {
	max = make([]string, len(data))
	min = make([]string, len(data))
	max = data[:n+1]
	min = data[len(data)-n-1:]
	sort.Sort(sort.Reverse(sort.StringSlice(min)))
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

func Check(signs []string, width int, num []string) bool {
	cur, pre := num[0], num[0]
	for i := 1; i < width; i++ {
		cur = num[i]
		switch signs[i-1] {
		case "<":
			if !(pre < cur) {
				return false
			}
		case ">":
			if !(pre > cur) {
				return false
			}
		}
		pre = cur
	}

	return true
}

// ref: https://ansohxxn.github.io/algorithm/permutation/
//func Permutation(data []string, depth, n, r int, res *[][]string) {
func Permutation(data []string, depth, n, r int) {
	if depth == r {
		//cur := make([]string, len(data))
		//copy(cur, data)
		//*res = append(*res, cur[:r])
		if Check(s, r, data[:r]) {
			min = Min(min, data[:r])
			max = Max(max, data[:r])
		}

		return
	}

	for i := depth; i < n; i++ {
		data[depth], data[i] = data[i], data[depth]
		//Permutation(data, depth+1, n, r, res)
		Permutation(data, depth+1, n, r)
		data[depth], data[i] = data[i], data[depth]
	}
}

// ref: https://velog.io/@geunwoobaek/permutation%EC%88%9C%EC%97%B4-%EA%B5%AC%ED%98%84
//func Reverse(s []string, i, n int) {
//	for i <= n {
//		i++
//		n--
//		s[i], s[n] = s[n], s[i]
//	}
//}

//func NextPermutation(s []string) bool {
//	j := len(s) - 1
//	i := j
//	for s[i-1] >= s[i] {
//		i--
//		if i == 0 {
//			return false
//		}
//	}
//
//	for s[j] <= s[i-1] {
//		j--
//		if j == 0 {
//			return false
//		}
//	}
//	s[j], s[i-1] = s[i-1], s[j]
//
//	Reverse(s, i, len(s)-1)
//	return true
//}

func Min(a, b []string) []string {
	res := make([]string, len(a))
	va, _ := strconv.Atoi(strings.Join(a, ""))
	vb, _ := strconv.Atoi(strings.Join(b, ""))
	if va < vb {
		copy(res, a)
	} else {
		copy(res, b)
	}

	return res
}

func Max(a, b []string) []string {
	res := make([]string, len(a))
	va, _ := strconv.Atoi(strings.Join(a, ""))
	vb, _ := strconv.Atoi(strings.Join(b, ""))
	if va > vb {
		copy(res, a)
	} else {
		copy(res, b)
	}

	return res
}

func Solve(n int, signs string) (string, string) {
	s = strings.Split(signs, " ")
	data := []string{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
	Init(n, data)
	Permutation(data, 0, 10, n+1)

	return strings.Join(max, ""), strings.Join(min, "")
}

func main() {
	n := ScanInt()
	str := ScanString()
	vmax, vmin := Solve(n, str)
	fmt.Printf("%s\n%s", vmax, vmin)
}
